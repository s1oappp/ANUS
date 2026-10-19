import struct, re, bisect, collections

PATH = r".zwork\attachments\5fe2b94a-8ba3-4f1a-9db2-6e9725a63641\usblsafe-327x.bin"
d = open(PATH, "rb").read()
n = len(d)
HDR = 0x3C0
BASE = 0x30004000
IMG_END_VA = BASE + (n - HDR)

# strip header payload + stub for Ghidra
open("usbl_payload_30004000.bin", "wb").write(d[HDR:])
open("usbl_stub_2ffe4000.bin", "wb").write(d[0x54:HDR])
print("payload bytes:", n - HDR, " stub bytes:", HDR - 0x54)

# dictionary of NUL-terminated strings by start offset
strmap = {}
for m in re.finditer(rb"[\x20-\x7e]{2,}\x00", d):
    off = m.start()
    va = off - HDR + BASE
    strmap[va] = m.group()[:-1].decode("ascii")
print("strings:", len(strmap))

cnt = n // 4
words = struct.unpack(f"<{cnt}I", d[:cnt*4])

def namep(w):
    s = strmap.get(w)
    if s is None: return None
    if len(s) < 2 or len(s) > 80: return None
    return s

# find runs of consecutive name pointers
runs = []
run = 0; start = None
for i in range(cnt):
    if namep(words[i]):
        if run == 0: start = i
        run += 1
    else:
        if run >= 10: runs.append((start, run))
        run = 0
if run >= 10: runs.append((start, run))

print("\n=== name-pointer array runs (>=10) ===")
for rs, rl in runs:
    o = rs * 4
    names = [namep(words[rs+k]) for k in range(min(rl, 6))]
    print(f"@file {o:08X} (VA {o-HDR+BASE:08X}) count={rl} names: {names}")

# for each run, try to locate a following values array
print("\n=== pairing attempt ===")
def ramish(w):
    return w == 0 or (BASE <= w < IMG_END_VA)

for rs, rl in runs:
    end = rs + rl
    best = None
    for off in range(end, min(end + 0x400, cnt - rl)):
        good = sum(1 for k in range(min(rl, 64)) if ramish(words[off + k]))
        frac = good / min(rl, 64)
        if best is None or frac > best[1]:
            best = (off, frac)
    if best and best[1] > 0.5:
        off = best[0]
        samp = [f"{words[off+k]:08X}" for k in range(min(rl, 8))]
        print(f"names@{rs*4:08X} n={rl} -> values@{off*4:08X} frac={best[1]:.2f} sample={samp}")
    else:
        print(f"names@{rs*4:08X} n={rl} -> no values array found (best={best})")
