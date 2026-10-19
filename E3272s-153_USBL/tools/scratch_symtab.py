import struct, re, collections

PATH = r".zwork\attachments\5fe2b94a-8ba3-4f1a-9db2-6e9725a63641\usblsafe-327x.bin"
d = open(PATH, "rb").read()
n = len(d)
BASE = 0x30004000       # VA of file offset 0x3C0 (payload start)
HDR = 0x3C0
IMG_END_VA = BASE + (n - HDR)

def va2off(va):
    off = va - BASE + HDR
    return off if HDR <= off < n else None

def str_at(off, maxlen=48):
    if off is None: return None
    end = off
    while end < n and end - off < maxlen and 32 <= d[end] < 127:
        end += 1
    if end < n and d[end] == 0 and end > off:
        return d[off:end].decode("ascii")
    return None

def word(off): return struct.unpack_from("<I", d, off)[0]

def dump_region(lo, hi, note):
    print(f"\n=== {note} ({lo:#X}-{hi:#X}) ===")
    for o in range(lo, hi, 16):
        ann = []
        for i in range(0, 16, 4):
            w = word(o+i)
            so = va2off(w)
            s = str_at(so, 40) if so is not None else None
            if s: ann.append(f"+{i}:{s}")
            elif BASE <= w < IMG_END_VA: ann.append(f"+{i}:VA")
        asc = "".join(chr(c) if 32 <= c < 127 else "." for c in d[o:o+16])
        words = " ".join(f"{word(o+i):08X}" for i in range(0, 16, 4))
        print(f"{o:08X}: {words} |{asc}| {' ; '.join(ann)}")

dump_region(0x1A9A00, 0x1AAC00, "tail cluster 1")
dump_region(0x1ABE40, 0x1AC400, "tail cluster 2")
dump_region(0x17CF00, 0x17D400, "mid cluster")
dump_region(0x172D40, 0x172E40, "symTbl names area")

# Build ASCII string VA ranges
str_ranges = []
for m in re.finditer(rb"[\x20-\x7e]{4,}", d):
    lo, hi = m.start(), m.end()
    str_ranges.append((lo, hi))
import bisect
starts = [r[0] for r in str_ranges]

def is_name_va(va):
    off = va2off(va)
    if off is None: return None
    i = bisect.bisect_right(starts, off) - 1
    if i >= 0:
        lo, hi = str_ranges[i]
        if lo <= off < hi: return str_at(lo, 64)
    return None

# scan for candidate symbol nodes: w0,w2 ram VA; w1 -> ascii string
print("\n=== symbol-node scan (stride 16) ===")
cnt = n // 4
words = struct.unpack(f"<{cnt}I", d[:cnt*4])
best = []
run = 0; run_start = None
runs = []
for i in range(cnt-4):
    w0, w1, w2, w3 = words[i], words[i+1], words[i+2], words[i+3]
    ok = (BASE <= w0 < IMG_END_VA and is_name_va(w1) and BASE <= w2 < IMG_END_VA and w3 < 0x100000)
    if ok:
        if run == 0: run_start = i
        run += 1
    else:
        if run >= 8:
            runs.append((run_start, run))
        run = 0
if run >= 8: runs.append((run_start, run))
total_syms = 0
for rs, rl in runs:
    print(f"node-run @file {rs*4:#X} count={rl}")
    total_syms += rl
print("total candidate symbols:", total_syms)

if runs:
    rs, rl = max(runs, key=lambda x: x[1])
    print(f"\n--- sample from biggest run @{rs*4:#X} ---")
    for i in range(rs, min(rs+15, rs+rl)):
        o = i*4
        w0, w1, w2, w3 = words[i], words[i+1] if False else None, None, None
        w0 = words[i]; w1 = words[i+1]; w2 = words[i+2]; w3 = words[i+3]
        print(f"{o:08X}: next={w0:08X} name={w1:08X}({is_name_va(w1)}) val={w2:08X} type={w3:#x}")

# also try stride 20
print("\n=== symbol-node scan (stride 20) ===")
run = 0; run_start = None; runs20 = []
for i in range(0, (n-24)//4):
    o = i*4
    w0, w1, w2 = words[i], words[i+1], words[i+2]
    w4, w5 = words[i+4], words[i+5]
    ok = (BASE <= w0 < IMG_END_VA and is_name_va(w1) and BASE <= w2 < IMG_END_VA
          and BASE <= w4 < IMG_END_VA and is_name_va(w5))
    if ok:
        if run == 0: run_start = i
        run += 1
    else:
        if run >= 8: runs20.append((run_start, run))
        run = 0
if run >= 8: runs20.append((run_start, run))
for rs, rl in runs20:
    print(f"node-run(20) @file {rs*4:#X} count={rl}")
