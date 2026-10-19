# -*- coding: utf-8 -*-
import re, struct, bisect

d = open('usbl_payload_30004000.bin', 'rb').read()
BASE = 0x30004000
wc = len(d) // 4
words = struct.unpack(f"<{wc}I", d[:wc*4])
dec = open('decompiled_all.c', encoding='utf-8', errors='replace').read().splitlines()

frows = []
with open('usbl_src/index/ALL_FUNCTIONS.tsv', encoding='utf-8') as f:
    for line in f.read().splitlines()[1:]:
        p = line.split('\t')
        if len(p) >= 7: frows.append((int(p[0], 16), p[1], p[2]))
frows.sort()

print("=== A. sysSerial* функции ===")
for a, n, m in frows:
    if 'Serial' in n or 'serial' in n:
        print(f"  {a:08X} {n} ({m})")

print("\n=== B. тела sysSerialHwInit / sysSerialHwInit2 ===")
for fn in ("sysSerialHwInit", "sysSerialHwInit2"):
    idx = [i for i, l in enumerate(dec) if f'==== {fn} @ ' in l]
    if idx:
        i1 = next((j for j in range(idx[0]+1, len(dec)) if '==== ' in dec[j] and ' @ 0x' in dec[j]), len(dec))
        print(f"--- {fn} ---")
        print("\n".join(dec[idx[0]:min(idx[0]+70, i1)]))

print("\n=== C. таблица каналов DAT_3000bcc4/bcc8/bccc + окрестности ===")
for va in range(0x3000BCC0, 0x3000BD00, 4):
    w = words[(va - BASE) // 4]
    print(f"  {va:08X}: {w:08X}")

print("\n=== D. разыменование таблицы каналов (первый уровень) ===")
for ptrva in (0x3000BCC4, 0x3000BCC8, 0x3000BCCC):
    w = words[(ptrva - BASE) // 4]
    print(f"  *{ptrva:08X} = {w:08X}")
    o = w - BASE
    if 0 <= o <= len(d) - 0x40:
        for k in range(0, 0x40, 4):
            w2 = words[(o + k) // 4]
            print(f"     +{k:02X}: {w2:08X}")

print("\n=== E. UpdateDevPidInfo: callers и profile-указатели ===")
cur = None
for i, l in enumerate(dec):
    m = re.match(r'/\* ==== (.+?) @ 0x([0-9A-F]+) ==== \*/', l)
    if m: cur = m.group(1); continue
    if 'UpdateDevPidInfo(' in l and cur != 'BSP_USB_UpdateDevPidInfo':
        print(f"  caller [{cur}]: {l.strip()[:110]}")
for dv in (0x3005AD08, 0x3005AD18, 0x3005AD20):
    w = words[(dv - BASE) // 4]
    print(f"  *{dv:08X} = {w:08X}")

print("\n=== F. профильные структуры: области 0x30181500-0x30181620 и 0x30181B00-0x30181B60 ===")
for lo, hi in ((0x30181500, 0x30181620), (0x30181B00, 0x30181B60)):
    for va in range(lo, hi, 16):
        o = va - BASE
        ann = []
        for k in range(0, 16, 4):
            w = words[(o + k) // 4]
            ann.append(f"{w:08X}")
        print(f"  {va:08X}: " + " ".join(ann))

print("\n=== G. кто пишет PID (grep '0x1c05' в коде) ===")
for i, l in enumerate(dec):
    if re.search(r'0[xX]0*1c05\b', l):
        last = None
        for j in range(i, -1, -1):
            m = re.match(r'/\* ==== (.+?) @ 0x([0-9A-F]+) ==== \*/', dec[j])
            if m: last = m.group(1); break
        print(f"  line {i+1} [{last}]: {l.strip()[:100]}")
