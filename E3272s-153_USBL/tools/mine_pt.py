# -*- coding: utf-8 -*-
import re, struct, collections, bisect

d = open('usbl_payload_30004000.bin', 'rb').read()
BASE = 0x30004000
wc = len(d) // 4
words = struct.unpack(f"<{wc}I", d[:wc*4])

def W(va): return words[(va - BASE) // 4] if BASE <= va < BASE + len(d) else None

print("=== 1. эталон DAT_3000511c (для 0x2ffffffc) ===")
print(f"  *0x3000511C = {W(0x3000511C):08X}")
print(f"  окрестность 0x30005110-0x30005140:", " ".join(f"{W(v):08X}" for v in range(0x30005110, 0x30005140, 4)))

print("\n=== 2. дефолтная ptable: DAT_3002c454 ===")
p = W(0x3002C454)
print(f"  *0x3002C454 = {p:08X}")
if p and BASE <= p < BASE + len(d):
    o = p - BASE
    print("  head (0x30 байт):")
    for k in range(0, 0x30, 4):
        print(f"    +{k:02X}: {words[(o+k)//4]:08X}")
    # records: head.size? посмотрим поля head: docs/06: bit0 +0x0C integrality; количество записей где-то в head
    # попробуем понять: после head идут записи по 0x30, в начале записи — имя (16 байт ASCII)
    # записи по 0x30: имя (16 байт) + offset/size/type/flags/seq
    R1 = {0x100: 'Ptable_R1', 0x101: 'Bootloader_R1', 0x102: 'Bootrom_R1', 0x550103: 'VxWorks_R1',
          0x104: 'Fastboot_R1', 0x105: 'Kernel_R1', 0x107: 'System_R1', 0x66: 'Nvimage_R1',
          0x113: 'WEBUI_R1', 0x109: 'APP_R1', 0x10D: 'NvBack_R1?', 0x10E: 'NvBack_R1?', 0x10C: '?', 0x10B: '?'}
    for rec in range(0, 24):
        ro = o + rec * 0x30
        if ro + 0x30 > len(d): break
        raw = d[ro:ro + 0x30]
        name = raw[:16].split(b'\x00')[0].decode('ascii', 'replace')
        w = struct.unpack('<12I', raw)
        off_, sz, typ, flg, seq = w[4], w[6], w[9], w[10], w[11]
        tname = R1.get(typ, '?')
        valid = 'V' if (flg & 8) else '-'
        print(f"  rec{rec:2d} @ {p + rec*0x30:08X}: {name:12s} off={off_:08X} size={sz:08X} type={typ:06X}({tname}) flags={flg:08X}[{valid}] seq={seq}")

print("\n=== 3. bands runtime: DAT_3000dd74/dd78/dd90 ===")
for dv in (0x3000DD74, 0x3000DD78, 0x3000DD90):
    w = W(dv)
    print(f"  *{dv:08X} = {w:08X}")
dd74 = W(0x3000DD74)
if dd74 and BASE <= dd74 < BASE + len(d):
    o = dd74 - BASE
    print(f"  *dd74 deref @{dd74:08X} (+0x00..+0x40):", " ".join(f"{words[(o+k)//4]:08X}" for k in range(0, 0x44, 4)))
dd90 = W(0x3000DD90)
if dd90 and BASE <= dd90 < BASE + len(d):
    o = dd90 - BASE
    print(f"  *dd90 deref @{dd90:08X} (3 слова):", " ".join(f"{words[(o+k)//4]:08X}" for k in range(0, 12, 4)))

print("\n=== 4. GPIO IRQ таблица DAT_300357bc/57c0 ===")
for dv in (0x300357BC, 0x300357C0):
    w = W(dv)
    print(f"  *{dv:08X} = {w:08X}")
    if w and BASE <= w < BASE + len(d):
        o = w - BASE
        print(f"    deref: " + " ".join(f"{words[(o+k)//4]:08X}" for k in range(0, 0x30, 4)))

print("\n=== 5. sysClk* тела (база таймера) ===")
dec = open('decompiled_all.c', encoding='utf-8', errors='replace').read().splitlines()
for fn in ("sysClkInit", "sysClkEnable", "sysClkConnect", "sysClkRateSet", "sysAuxClkEnable", "sysAuxClkConnect"):
    idx = [i for i, l in enumerate(dec) if f'==== {fn} @ ' in l]
    if idx:
        i1 = next((j for j in range(idx[0]+1, len(dec)) if '==== ' in dec[j] and ' @ 0x' in dec[j]), len(dec))
        body = "\n".join(dec[idx[0]:min(idx[0]+40, i1)])
        dats = sorted(set(re.findall(r'DAT_[0-9a-f]{8}', body)))
        consts = sorted(set(re.findall(r'0x[0-9a-fA-F]{4,8}', body)))
        print(f"--- {fn} --- DATs: {dats[:8]} consts: {consts[:12]}")
        for dv in dats[:8]:
            w = W(int(dv[4:], 16))
            if w: print(f"    {dv} = {w:08X}")

print("\n=== 6. nandc/nand: ВСЕ DAT-значения (расширенно) ===")
cur = None
vals = collections.Counter()
where = {}
for i, l in enumerate(dec):
    m = re.match(r'/\* ==== (.+?) @ 0x([0-9A-F]+) ==== \*/', l)
    if m: cur = m.group(1); continue
    if cur and re.match(r'^(nandc|nand|Nand)', cur or ''):
        for dv in re.findall(r'DAT_([0-9a-f]{8})', l):
            w = W(int(dv, 16))
            if w and w != 0 and (w < 0x30000000 or w > 0x30200000):
                vals[w] += 1
                where.setdefault(w, cur)
for w, c in vals.most_common(30):
    print(f"  {w:08X} x{c}  ({where[w]})")

print("\n=== 7. второй USB-профиль: 0x301815B0-0x30181640 байтовый поток u16 ===")
o = 0x301815B0 - BASE
stream = []
for k in range(0, 0x90, 2):
    stream.append(struct.unpack_from('<H', d, o + k)[0])
print("  u16:", " ".join(f"{x:04X}" for x in stream))
