import struct, re, sys

PATH = r".zwork\attachments\5fe2b94a-8ba3-4f1a-9db2-6e9725a63641\usblsafe-327x.bin"
d = open(PATH, "rb").read()
n = len(d)
print("size:", hex(n))

def rows(off, length, base=0):
    for o in range(off, min(off+length, n), 16):
        chunk = d[o:o+16]
        words = " ".join(f"{struct.unpack('<I', chunk[i:i+4])[0]:08X}" for i in range(0, len(chunk)-3, 4))
        asc = "".join(chr(c) if 32 <= c < 127 else "." for c in chunk)
        print(f"{o:08X}: {words:<44} |{asc}|")

print("\n--- header 0x000-0x3C0 ---")
rows(0, 0x3C0)

print("\n--- payload start 0x3C0 ---")
rows(0x3C0, 0x80)

print("\n--- tail 0x1AC400-0x1AC54C ---")
rows(n-0x14C, 0x14C)

# JPEG check
print("\nbytes at 0xD7840:", d[0xD7840:0xD7850].hex(" "))

# pointer cluster scan
print("\n--- pointer cluster scan (0x30000000-0x30200000) ---")
cnt = n // 4
words = struct.unpack(f"<{cnt}I", d[:cnt*4])
run_start = None
for i, w in enumerate(words):
    inram = 0x2FFE0000 <= w < 0x30200000
    if inram and run_start is None:
        run_start = i
    elif not inram and run_start is not None:
        if i - run_start >= 16:
            print(f"off {run_start*4:08X}..{i*4:08X} len={i-run_start} words")
        run_start = None
if run_start is not None and cnt - run_start >= 16:
    print(f"off {run_start*4:08X}..{cnt*4:08X} len={cnt-run_start} words (to EOF)")

print("\n--- name-pointer nodes (ptr into 0x12A000-0x180000 as 2nd word) ---")
hits = 0
first = []
for o in range(0, cnt*4 - 16, 4):
    w1, w2, w3 = words[o//4], words[o//4+1], words[o//4+2]
    if 0x2FFE0000 <= w1 < 0x30200000 and 0x120000 <= w2 < 0x180000 and 0x2FFE0000 <= w3 < 0x30200000:
        hits += 1
        if len(first) < 20: first.append(o*4)
print("candidate nodes:", hits, "first:", [hex(x) for x in first])

def ctx(off, back=0x180, fwd=0x300):
    print(f"\n--- strings context @{off:#X} ---")
    b0 = max(0, off-back)
    for m in re.finditer(rb"[\x20-\x7e]{6,}", d[b0:off+fwd]):
        print(f"{b0+m.start():08X}: {m.group().decode('ascii','replace')[:100]}")

ctx(0x151DC0)   # VxWorks
ctx(0x15E7D3)   # Build
ctx(0x1679AE)   # Build
ctx(0x12C39E)   # Version
ctx(0x1302A9)   # GCC

for s in [b"sysInit", b"usrInit", b"usrRoot", b"vxWorks", b"symTbl", b"VxWorks 6", b"VxWorks5", b"VxWorks 5", b"_func_", b"sysClk", b"taskSpawn"]:
    idx = []
    start = 0
    while True:
        i = d.find(s, start)
        if i < 0 or len(idx) >= 10: break
        idx.append(i); start = i + 1
    print(s.decode(), [hex(x) for x in idx], "total", d.count(s))

# full strings dump for later
with open("scratch_strings.txt", "w", encoding="utf-8", errors="replace") as f:
    for m in re.finditer(rb"[\x20-\x7e]{5,}", d):
        f.write(f"{m.start():08X} {m.group().decode('ascii','replace')}\n")
    for m in re.finditer(rb"(?:[\x20-\x7e]\x00){5,}", d):
        s = m.group().decode("utf-16le", "replace")
        f.write(f"{m.start():08X} [UTF16] {s}\n")
print("\nstrings dumped to scratch_strings.txt")
