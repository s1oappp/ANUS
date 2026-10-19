# -*- coding: utf-8 -*-
import re, struct, collections, bisect, csv

d = open('usbl_payload_30004000.bin', 'rb').read()
BASE = 0x30004000
dec = open('decompiled_all.c', encoding='utf-8', errors='replace').read().splitlines()

frows = []
with open('usbl_src/index/ALL_FUNCTIONS.tsv', encoding='utf-8') as f:
    for line in f.read().splitlines()[1:]:
        p = line.split('\t')
        if len(p) >= 7: frows.append((int(p[0], 16), p[1], p[2]))
frows.sort()
fstarts = [a for a, n, m in frows]

def owner(va):
    i = bisect.bisect_right(fstarts, va) - 1
    return frows[i][1] if i >= 0 else None

# маркеры для границ функций в decompiled
marks = []
for i, l in enumerate(dec):
    m = re.match(r'/\* ==== (.+?) @ 0x([0-9A-F]+) ==== \*/', l)
    if m: marks.append((i, m.group(1), int(m.group(2), 16)))

def enclosing(lineno):
    last = None
    for i, n, a in marks:
        if i > lineno: break
        last = (n, a)
    return last

print("=== A. контексты 0x10000000 (256MB) ===")
seen = collections.Counter()
for i, l in enumerate(dec):
    if re.search(r'0[xX]0*10000000\b', l):
        n = enclosing(i)
        seen[n[0] if n else '?'] += 1
for k, c in seen.most_common(12):
    print(f"  {k:34s} x{c}")

print("\n=== B. intConnect ( loose ) ===")
cnt = collections.Counter()
ctx2 = {}
cur = None
for i, l in enumerate(dec):
    m = re.match(r'/\* ==== (.+?) @ 0x([0-9A-F]+) ==== \*/', l)
    if m: cur = m.group(1); continue
    if 'intConnect' in l:
        nums = re.findall(r'0x[0-9a-fA-F]+|\b\d+\b', l)
        cnt[(cur, l.strip()[:110])] += 1
for (fn, l), c in list(cnt.items())[:30]:
    print(f"  [{fn}] {l}")

print("\n=== C. sysHwInit2 / sysHwInit / sysHwInit0 тела ===")
for fn in ("sysHwInit2", "sysHwInit", "sysHwInit0"):
    idx = [i for i, l in enumerate(dec) if f'==== {fn} @ ' in l]
    if idx:
        i1 = next((j for j in range(idx[0]+1, len(dec)) if '==== ' in dec[j] and ' @ 0x' in dec[j]), len(dec))
        print(f"--- {fn} ---")
        print("\n".join(dec[idx[0]:min(idx[0]+60, i1)][:60]))

print("\n=== D. nandc: MMIO-кандидаты (DAT-слова из тел nandc_*) ===")
dats = collections.Counter()
cur = None
for i, l in enumerate(dec):
    m = re.match(r'/\* ==== (.+?) @ 0x([0-9A-F]+) ==== \*/', l)
    if m: cur = m.group(1); continue
    if cur and cur.startswith(('nandc', 'nand')):
        for dv in re.findall(r'DAT_([0-9a-f]{8})', l):
            off = int(dv, 16) - BASE
            if 0 <= off <= len(d) - 4:
                w = struct.unpack_from('<I', d, off)[0]
                if 0x90000000 <= w < 0x90100000 or 0x10000000 <= w < 0x10100000:
                    dats[(w, dv)] += 1
for (w, dv), c in dats.most_common(15):
    print(f"  DAT_{dv} = {w:08X}  x{c}")

print("\n=== E. литералы 1e9: владельцы ===")
for va in (0x300E07A0, 0x300E6070):
    print(f"  {va:08X}: {owner(va)}")

print("\n=== F. UpdateDevPidInfo: откуда PID ===")
idx = [i for i, l in enumerate(dec) if '==== BSP_USB_UpdateDevPidInfo @ ' in l]
if idx:
    i1 = next((j for j in range(idx[0]+1, len(dec)) if '==== ' in dec[j] and ' @ 0x' in dec[j]), len(dec))
    print("\n".join(dec[idx[0]:min(idx[0]+45, i1)]))

print("\n=== G. '0x8000000' (128MB) и '0x7f00000' ===")
for pat in (r'0[xX]0*8000000\b', r'0[xX]0*7f00000\b', r'0[xX]0*3f00000\b'):
    n = 0; ex = None
    for l in dec:
        if re.search(pat, l):
            n += 1
            if ex is None: ex = l.strip()[:100]
    print(pat, n, ex)
