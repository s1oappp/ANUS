import struct, re, csv

PATH = r".zwork\attachments\5fe2b94a-8ba3-4f1a-9db2-6e9725a63641\usblsafe-327x.bin"
d = open(PATH, "rb").read()
n = len(d)
HDR = 0x3C0
BASE = 0x30004000
IMG_END_VA = BASE + (n - HDR)

strmap = {}
for m in re.finditer(rb"[\x20-\x7e]{2,}\x00", d):
    strmap[m.start() - HDR + BASE] = m.group()[:-1].decode("ascii", "replace")

cnt = n // 4
words = struct.unpack(f"<{cnt}I", d[:cnt*4])

ident = re.compile(r"^[A-Za-z_$][A-Za-z0-9_$]{1,100}$")
rows = []
o = 0
while o + 16 <= n - 3:
    name_va = words[o//4]
    val = words[o//4 + 1]
    if words[o//4 + 3] == 0x00050000 and val != 0 and BASE <= val < IMG_END_VA:
        s = strmap.get(name_va)
        if s and len(s) >= 2 and len(s) <= 120:
            typ = words[o//4 - 2] if o >= 8 else 0
            rows.append((o, val, s, typ))
    o += 4

print("raw matches:", len(rows))

# contiguity: cluster matches closer than 64 bytes
clusters = []
for r in rows:
    if clusters and r[0] - clusters[-1][-1][0] <= 64:
        clusters[-1].append(r)
    else:
        clusters.append([r])
print("clusters:", [(hex(c[0][0]), hex(c[-1][0]), len(c)) for c in clusters if len(c) > 5])

good = [r for r in rows if ident.match(r[2])]
print("identifier-like:", len(good))
vas = sorted(set(v for _, v, _, _ in good))
print("unique VAs:", len(vas), "min", hex(vas[0]), "max", hex(vas[-1]))
names = {}
dup = 0
for _, v, s, _t in good:
    if s in names and names[s] != v: dup += 1
    names.setdefault(s, v)
print("unique names:", len(names), "name->multi-VA conflicts:", dup)

with open("symbols.csv", "w", newline="", encoding="utf-8") as f:
    w = csv.writer(f)
    w.writerow(["va_hex", "name", "type_word", "node_file_off"])
    for off, v, s, t in sorted(good, key=lambda r: (r[1], r[2])):
        w.writerow([f"{v:08X}", s, f"{t:08X}", f"{off:08X}"])
print("saved symbols.csv")

# sanity samples
import random
random.seed(1)
print("\nsamples:")
for r in random.sample(good, 15):
    print(f"  {r[1]:08X} {r[2]} (node@{r[0]:08X}, type {r[3]:08X})")

# distribution by region
import collections
c = collections.Counter()
for _, v, _, _ in good:
    c[v >> 20] += 1
print("\nVA distribution (per 1MB):", {f"{k:03X}xxxxx": cnt2 for k, cnt2 in sorted(c.items())})
