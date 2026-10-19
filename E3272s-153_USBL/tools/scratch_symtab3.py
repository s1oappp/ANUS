import struct, re

PATH = r".zwork\attachments\5fe2b94a-8ba3-4f1a-9db2-6e9725a63641\usblsafe-327x.bin"
d = open(PATH, "rb").read()
n = len(d)
HDR = 0x3C0
BASE = 0x30004000
IMG_END_VA = BASE + (n - HDR)

# string map
strmap = {}
for m in re.finditer(rb"[\x20-\x7e]{2,}\x00", d):
    strmap[m.start() - HDR + BASE] = m.group()[:-1].decode("ascii", "replace")

def va2off(va):
    off = va - BASE + HDR
    return off if HDR <= off < n else None

def str_at_va(va, maxlen=60):
    off = va2off(va)
    if off is None: return None
    end = off
    while end < n and end - off < maxlen and 32 <= d[end] < 127:
        end += 1
    if end < n and d[end] == 0 and end > off:
        return d[off:end].decode("ascii")
    return None

def is_code(va): return BASE <= va < IMG_END_VA

cnt = n // 4
words = struct.unpack(f"<{cnt}I", d[:cnt*4])

targets = [b"sysInit", b"usrInit", b"usrRoot", b"symTblCreate", b"symTblAdd",
           b"taskSpawn", b"semBCreate", b"printf", b"malloc", b"kernelTimeSlice",
           b"taskName", b"shellInit", b"vxMemProbe", b"intConnect"]

for t in targets:
    for m in re.finditer(re.escape(t) + rb"\x00", d):
        off = m.start()
        va = off - HDR + BASE
        hits = [i for i in range(cnt) if words[i] == va]
        print(f"\n### '{t.decode()}' @file {off:08X} VA {va:08X} ptr-hits: {[hex(h*4) for h in hits[:10]]} (total {len(hits)})")
        for h in hits[:6]:
            o = h * 4
            print(f"  context @ {o:08X}:")
            for k in range(-4, 5):
                oo = o + k*4
                if 0 <= oo < n - 3:
                    w = struct.unpack_from("<I", d, oo)[0]
                    ann = ""
                    s = str_at_va(w)
                    if s: ann = f"str:{s[:40]}"
                    elif is_code(w): ann = "VA(code?)"
                    print(f"    {oo:08X}: {w:08X} {ann}")
