# -*- coding: utf-8 -*-
"""
make_rebuild.py — восстановление сборки usblsafe-327x.bin из ассемблерного исходника.

  python make_rebuild.py gen    — сгенерировать header.s / stub.s / body.s (+ manifest)
  python make_rebuild.py build  — собрать обратно (Keystone) и сверить SHA-256 с оригиналом
  python make_rebuild.py all    — gen + build

Идея: каждая 4-байтная позиция кода либо кодируется как инструкция (и проверяется, что
ассемблер даёт РОВНО те же байты), либо выводится директивой .word — поэтому сборка
гарантированно побайтно совпадает с оригиналом, а весь «непрозрачный» код остаётся
читаемым ассемблером.
"""
import os, sys, struct, hashlib, re
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM
from keystone import Ks, KS_ARCH_ARM, KS_MODE_ARM, KsError

ROOT = os.path.dirname(os.path.abspath(__file__))
ORIG = os.path.join(ROOT, '.zwork', 'attachments', '5fe2b94a-8ba3-4f1a-9db2-6e9725a63641', 'usblsafe-327x.bin')
OUTDIR = os.path.join(ROOT, 'src_rebuild')

HEADER_LEN = 0x3C0
STUB_OFF, STUB_LEN, STUB_VA = 0x54, HEADER_LEN - 0x54, 0x2FFE4000
BODY_OFF, BODY_VA = 0x3C0, 0x30004000

md = Cs(CS_ARCH_ARM, CS_MODE_ARM)
ks = Ks(KS_ARCH_ARM, KS_MODE_ARM)
ks_broken = False

def load_syms():
    """VA -> имя функции (для комментариев переходов)"""
    syms = {}
    p = os.path.join(ROOT, 'symbols.csv')
    if os.path.exists(p):
        with open(p, encoding='utf-8') as f:
            next(f, None)
            for line in f:
                parts = line.strip().split(',')
                if len(parts) >= 2:
                    try: syms[int(parts[0], 16)] = parts[1]
                    except ValueError: pass
    return syms

def esc_bytes(b):
    return ",".join(f"0x{x:02x}" for x in b)

def try_encode(text, va, want):
    """подобрать синтаксис, который ассемблируется РОВНО в байты want"""
    global ks_broken
    if ks_broken:
        return None
    cands = [text]
    t2 = re.sub(r'\b(b|bl|bx|blx)\s+#', r'\1 ', text)
    if t2 != text: cands.append(t2)
    t3 = re.sub(r'\s+#(?=[0-9])', ' ', text)  # убрать # перед числами (coproc/psr)
    if t3 not in cands: cands.append(t3)
    for t in cands:
        try:
            enc, cnt = ks.asm(t, va, True)
        except KsError:
            continue
        except (OSError, MemoryError, Exception) as e:
            # keystone может падать AV на экзотике; проверить здоровье и продолжить
            try:
                ks.asm('mov r0, r0', va, True)
            except Exception:
                ks_broken = True
                print('  KEYSTONE UNSTABLE -> остальные слова пойдут как .word (точность сохранится)')
            continue
        if cnt == 1 and bytes(enc) == want:
            return t
    return None

def emit_code(f, data, base_off, va_base, syms, banner):
    """линейный проход по региону: инструкции с побайтовой проверкой, иначе .word"""
    n = len(data)
    f.write(banner)
    # собрать адреса литеральных пулов (ldr/ldrd [pc, #imm])
    pools = set()
    for ins in md.disasm(data, va_base):
        if ins.mnemonic in ('ldr', 'ldrd') and '[pc' in ins.op_str:
            m = re.search(r'#(-?\d+)', ins.op_str)
            if m:
                tgt = (ins.address + 8 + int(m.group(1))) & ~3
                rel = tgt - va_base
                if 0 <= rel < n: pools.add(rel)
    off = 0
    stats = {'insn': 0, 'word': 0}
    last_func = None
    while off < n:
        va = va_base + off
        w = data[off:off+4]
        # баннер функции при попадании на её начало
        if va in syms and va != last_func:
            last_func = va
            f.write("\n; =============== %s @ 0x%08X ===============\n" % (syms[va], va))
        if len(w) == 4 and (off not in pools):
            ins_list = list(md.disasm(w, va))
            if len(ins_list) == 1 and ins_list[0].size == 4:
                ins = ins_list[0]
                text = (ins.mnemonic + ' ' + ins.op_str).strip()
                ok = try_encode(text, va, w)
                if ok:
                    line = "    %-46s @ %08X" % (ok, va)
                    if ins.mnemonic in ('b', 'bl', 'bx', 'blx') or ins.mnemonic.startswith('b'):
                        m = re.search(r'#?(0x[0-9a-f]+)', ins.op_str)
                        if m:
                            t = int(m.group(1), 16)
                            nm = syms.get(t)
                            line += " ; -> " + (nm if nm else "0x%08X" % t)
                    f.write(line + "\n")
                    stats['insn'] += 1
                    off += 4
                    continue
        word = struct.unpack('<I', w)[0] if len(w) == 4 else None
        if word is not None:
            f.write("    .word 0x%08X                              @ %08X\n" % (word, va))
            stats['word'] += 1
            off += 4
        else:
            f.write("    .byte " + esc_bytes(w) + "                              @ %08X\n" % va)
            stats['word'] += 1
            off += len(w)
    return stats

def emit_data(f, data, va_base, banner):
    """данные: печатные строки -> .asciz, остальное .byte"""
    f.write(banner)
    off, n = 0, len(data)
    while off < n:
        m = re.match(rb"[\x20-\x7e]{4,}\x00", data[off:])
        if m:
            s = m.group()[:-1].decode('ascii')
            e = s.replace('\\', '\\\\').replace('"', '\\"')
            f.write('    .asciz "%s"\n' % e)
            off += m.end()
            continue
        chunk = data[off:off+16]
        f.write("    .byte " + esc_bytes(chunk) + "  @ %08X\n" % (va_base + off))
        off += len(chunk)

def gen():
    if not os.path.exists(ORIG):
        sys.exit('нет исходного бинарника: ' + ORIG)
    d = open(ORIG, 'rb').read()
    os.makedirs(OUTDIR, exist_ok=True)
    syms = load_syms()

    header = d[:0x54]
    with open(os.path.join(OUTDIR, 'header.s'), 'w', encoding='utf-8') as f:
        f.write("; Заголовок образа usblsafe-327x.bin (0x000-0x053), данные для bootrom.\n")
        f.write("; Поля: +0x2C=0x2FFE4000 (вход стаба), +0x38=0x1AC18C (размер тела),\n")
        f.write(";        +0x3C=0x30004000 (адрес загрузки тела), +0x40=0x3C0 (смещение тела).\n")
        f.write("    .byte " + esc_bytes(header) + "\n")

    stats = {}
    with open(os.path.join(OUTDIR, 'stub.s'), 'w', encoding='utf-8') as f:
        f.write("; Стаб первого уровня: файл 0x054-0x3BF, исполняется в IRAM 0x2FFE4000.\n")
        f.write("; Настраивает DDR-контроллер 0x90020000 и системный блок 0x90000000, возвращает управление.\n")
        stats['stub'] = emit_code(f, d[STUB_OFF:STUB_OFF+STUB_LEN], STUB_OFF, STUB_VA, syms, "\n")

    body = d[BODY_OFF:]
    code_len = 0x12A42B - BODY_OFF      # код до начала строк (VA 0x3012E06B)
    with open(os.path.join(OUTDIR, 'body.s'), 'w', encoding='utf-8') as f:
        f.write("; Тело VxWorks 6.8: файл 0x3C0-конец, исполняется в SDRAM 0x30004000.\n")
        f.write("; Код: 0x30004000-0x3012E06B; далее строки и данные.\n")
        stats['body_code'] = emit_code(f, body[:code_len], BODY_OFF, BODY_VA, syms, "\n; ---- код ----\n")
        emit_data(f, body[code_len:], BODY_VA + code_len, "\n; ---- строки и данные ----\n")

    with open(os.path.join(OUTDIR, 'build_info.txt'), 'w', encoding='utf-8') as f:
        f.write("original_sha256=%s\n" % hashlib.sha256(d).hexdigest())
        f.write("original_size=%d\n" % len(d))
        f.write("header_len=%d stub_len=%d body_len=%d\n" % (0x54, STUB_LEN, len(body)))
        for k, v in stats.items():
            f.write("%s: insn=%d word=%d\n" % (k, v.get('insn', 0) if isinstance(v, dict) else 0))
    print('gen OK:', stats, 'size', len(d))

def parse_and_build(src, va_base):
    """собрать .s -> bytes (keystone). Поддержка .byte/.word/.asciz и инструкций."""
    out = bytearray()
    errs = 0
    with open(src, encoding='utf-8') as f:
        for lineno, line in enumerate(f, 1):
            stripped = line.rstrip('\r\n').strip()
            if not stripped:
                continue
            if stripped.startswith('.byte'):
                vals = [int(x, 16) for x in re.findall(r'0x([0-9a-fA-F]{2})', stripped)]
                out += bytes(vals)
                continue
            if stripped.startswith('.word'):
                for v in re.findall(r'0x([0-9a-fA-F]{8})', stripped):
                    out += struct.pack('<I', int(v, 16))
                continue
            if stripped.startswith('.asciz'):
                m = re.search(r'"((?:\\.|[^"\\])*)"', stripped)
                if m:
                    s = m.group(1).encode().decode('unicode_escape')
                    out += s.encode('latin-1') + b'\x00'
                continue
            # инструкция: убрать комментарии (после @ или ;)
            code = stripped.split('@')[0].split(';')[0].rstrip()
            if not code:
                continue
            try:
                enc, cnt = ks.asm(code, va_base + len(out), True)
                if cnt != 1:
                    raise KsError('multi')
                out += bytes(enc)
            except KsError as e:
                errs += 1
                print('  ERR %s:%d %r (%s)' % (os.path.basename(src), lineno, code, e))
                out += b'\x00\x00\x00\x00'
    return bytes(out), errs

def build():
    d = open(ORIG, 'rb').read()
    parts = []
    total_errs = 0
    for name, va, ln in (('header.s', 0, 0x54), ('stub.s', STUB_VA, STUB_LEN), ('body.s', BODY_VA, len(d) - BODY_OFF)):
        b, errs = parse_and_build(os.path.join(OUTDIR, name), va)
        total_errs += errs
        expect = d[0:0x54] if name == 'header.s' else (d[STUB_OFF:STUB_OFF+STUB_LEN] if name == 'stub.s' else d[BODY_OFF:])
        if b != expect:
            bad = next((i for i in range(min(len(b), len(expect))) if b[i] != expect[i]), min(len(b), len(expect)))
            print('%s: ДИФФ на смещении 0x%X (len %d vs %d)' % (name, bad, len(b), len(expect)))
        else:
            print('%s: OK (%d байт)' % (name, len(b)))
        parts.append(b)
    img = parts[0] + parts[1] + parts[2]
    os.makedirs(os.path.join(OUTDIR, 'out'), exist_ok=True)
    outp = os.path.join(OUTDIR, 'out', 'usblsafe-327x.bin')
    open(outp, 'wb').write(img)
    h, ho = hashlib.sha256(img).hexdigest(), hashlib.sha256(d).hexdigest()
    print('rebuilt :', len(img), h)
    print('original:', len(d), ho)
    print('MATCH' if img == d and h == ho else 'MISMATCH', '| errors:', total_errs)

if __name__ == '__main__':
    cmd = sys.argv[1] if len(sys.argv) > 1 else 'all'
    if cmd in ('gen', 'all'): gen()
    if cmd in ('build', 'all'): build()
