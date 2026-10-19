# -*- coding: utf-8 -*-
import re, struct, csv, collections, bisect

d = open('usbl_payload_30004000.bin', 'rb').read()
BASE = 0x30004000
wc = len(d) // 4
words = struct.unpack(f"<{wc}I", d[:wc*4])
strs = []
for m in re.finditer(rb"[\x20-\x7e]{2,}\x00", d):
    strs.append((m.start(), m.group()[:-1].decode('ascii', 'replace')))
starts = [s[0] for s in strs]

def va_str(va, maxlen=50):
    off = va - BASE
    if off < 0 or off >= len(d): return None
    i = bisect.bisect_right(starts, off) - 1
    if i >= 0 and starts[i] == off: return strs[i][1][:maxlen]
    return None

funcs = {}
with open('usbl_src/index/ALL_FUNCTIONS.tsv', encoding='utf-8') as f:
    for line in f.read().splitlines()[1:]:
        p = line.split('\t')
        if len(p) >= 7: funcs[p[1]] = (int(p[0], 16), p[2], p[3])

dec = open('decompiled_all.c', encoding='utf-8', errors='replace').read().splitlines()

def func_body(name):
    """тело функции из decompiled_all.c по маркеру"""
    pat = f'==== {name} @ '
    idx = [i for i, l in enumerate(dec) if pat in l]
    if not idx: return None, None
    i0 = idx[0]
    i1 = next((j for j in range(i0 + 1, len(dec)) if '==== ' in dec[j] and ' @ 0x' in dec[j]), len(dec))
    va = int(re.search(r'@ 0x([0-9A-F]+)', dec[i0]).group(1), 16)
    return va, "\n".join(dec[i0:i1])

print("=== A. запись продукта E3272S-153 (id 0x301) ===")
o = 0x3012FCE0 - BASE
for k in range(0, 0x50, 4):
    w = words[(o + k) // 4]
    s = va_str(w)
    print(f"  {0x3012FCE0 + k:08X}: {w:08X}  {s if s else ''}")

print("\n=== B. BSP_GetSupportBands / GetSupportBandsForGu ===")
for fn in ("BSP_GetSupportBands", "BSP_GetSupportBandsForGu"):
    va, body = func_body(fn)
    print(f"--- {fn} @ {va:#x} ---")
    if body: print(body[:2500])

print("\n=== C. полосы: строки-кандидаты ===")
for pat in ("B1", "B3", "B5", "B7", "B8", "B20", "B38", "B41", "LTE", "GSM", "WCDMA", "TDD", "FDD", "band"):
    hits = [(off, s) for off, s in strs if pat in s and len(s) < 40]
    if hits:
        print(pat, [(hex(o + BASE), s[:26]) for o, s in hits[:5]])

print("\n=== D. RAM: блок kernelInit + константы размеров ===")
for va in range(0x300405D0, 0x30040620, 4):
    w = words[(va - BASE) // 4]
    s = va_str(w)
    print(f"  {va:08X}: {w:08X}  {s if s else ''}")
cnts = collections.Counter()
for i, l in enumerate(dec):
    for m in re.finditer(r'\b0(0?[0-9a-fA-F]{7,8})\b', l):
        pass
for c in (0x10000000, 0x08000000, 0x04000000, 0x0C000000, 0x0F000000, 0x02000000):
    n = 0
    ex = None
    for l in dec:
        if re.search(r'0[xX]0*%08X\b' % c, l):
            n += 1
            if ex is None: ex = l.strip()[:90]
    print(f"const 0x{c:08X}: {n}  ex: {ex}")

print("\n=== E. USB профили: таблица 0x301815BC ===")
for k in range(0, 0x60, 4):
    va = 0x301815BC + k
    w = words[(va - BASE) // 4]
    print(f"  {va:08X}: {w:08X}")

print("\n=== F. intConnect: номера прерываний ===")
hits = collections.Counter()
ctx = {}
cur = None
for l in dec:
    m = re.match(r'/\* ==== (.+?) @ 0x([0-9A-F]+) ==== \*/', l)
    if m: cur = m.group(1); continue
    m = re.search(r'intConnect\(([^,]+),([^,]+),([^,]+),([^,]+)\)', l)
    if m and cur:
        a = m.group(1).strip()
        key = a
        hits[key] += 1
        ctx.setdefault(key, (cur, m.group(2).strip()))
for k, n in sorted(hits.items(), key=lambda x: -x[1])[:25]:
    print(f"  IRQ-arg {k:20s} x{n}  first: {ctx[k][0]} -> {ctx[k][1][:40]}")

print("\n=== G. UART/консоль ===")
uarts = [(n, a) for n, (a, m, f) in funcs.items() if re.match(r'^(uart|UART|serial|Serial)', n)]
print("uart-символы:", uarts[:12], "всего", len(uarts))
for i, l in enumerate(dec):
    if 'HiLteFe' in l:
        st = max(0, i - 300)
        seg = "\n".join(dec[st:i + 1])
        m = re.findall(r'/\* ==== (.+?) @ 0x([0-9A-F]+) ==== \*/', seg)
        print("bootline use:", m[-1] if m else None, "|", l.strip()[:100])

print("\n=== H. NAND: база регистров и геометрия ===")
for fn in ("nandc_ctrl_entry", "nandc_init", "nand_init"):
    va, body = func_body(fn)
    if not body: continue
    print(f"--- {fn} @ {va:#x} (первые MMIO-константы) ---")
    dats = re.findall(r'DAT_([0-9a-f]{8})', body)[:10]
    for dv in dats:
        wva = int(dv, 16)
        if 0x30004000 <= wva < 0x301B018C:
            w = words[(wva - BASE) // 4]
            print(f"   DAT_{dv} = {w:08X}")
    for m in re.findall(r'0x[0-9a-fA-F]{3,8}', body):
        pass
    print("   consts:", sorted(set(re.findall(r'0x(?:00)?[0-9a-fA-F]{4,8}', body)))[:24])

print("\n=== I. частоты ===")
for c in (0x2FAF0800, 0x47868C00, 0x1DCD6500, 0x3B9ACA00, 0x5F5E1000, 0x11E1A300):
    hits = [l.strip()[:90] for l in dec if re.search(r'0[xX]0*%08X\b' % c, l)]
    if hits: print(f"0x{c:08X}: {hits[:2]}")
# в payload
for c in (0x2FAF0800, 0x47868C00, 0x1DCD6500, 0x3B9ACA00):
    b = struct.pack('<I', c)
    offs = [m.start() for m in re.finditer(re.escape(b), d)][:3]
    if offs: print(f"payload 0x{c:08X} @ {[hex(o + BASE) for o in offs]}")
