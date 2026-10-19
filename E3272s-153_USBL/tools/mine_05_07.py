# -*- coding: utf-8 -*-
import re, struct, collections, bisect

d = open('usbl_payload_30004000.bin', 'rb').read()
BASE = 0x30004000
wc = len(d) // 4
words = struct.unpack(f"<{wc}I", d[:wc*4])
strs = []
for m in re.finditer(rb"[\x20-\x7e]{2,}\x00", d):
    strs.append((m.start(), m.group()[:-1].decode('ascii', 'replace')))
starts = [s[0] for s in strs]

def va_str(va, maxlen=60):
    off = va - BASE
    if off < 0 or off >= len(d): return None
    i = bisect.bisect_right(starts, off) - 1
    if i >= 0 and starts[i] == off:
        return strs[i][1][:maxlen]
    return None

func_rows = []
with open('usbl_src/index/ALL_FUNCTIONS.tsv', encoding='utf-8') as f:
    for line in f.read().splitlines()[1:]:
        p = line.split('\t')
        if len(p) >= 7:
            func_rows.append((int(p[0], 16), p[1], p[2], int(p[4])))
names = [n for _, n, _, _ in func_rows]

print("=== 4. компоненты ядра по символам ===")
def cnt_pat(pat): return len([n for n in names if re.match(pat, n)])
for pat, lbl in [(r'^(tcp_|udp_|tcp$|udp$|ip$|icmp|igmp|arp)', 'tcp/udp/ip/icmp/arp'),
                 (r'^(mbuf|netBuf|net[A-Z]|if_?($|[A-Z]))', 'mbuf/net/if'),
                 (r'^(socket|sock[A-Z]|so_[a-z])', 'socket'),
                 (r'^(route|rt_?|ifRoute|hostAdd|hostGet|hostShow)', 'route/host'),
                 (r'^(wdb|Wdb)', 'wdb'),
                 (r'^(cplus)', 'cplus'),
                 (r'^(edr|Edr|EDR)', 'ED&R'),
                 (r'^(env|envPrivate)', 'env'),
                 (r'^(dosFs|dos[VV]ol|cbio|tffs)', 'dosFs/tffs'),
                 (r'^(nfs)', 'nfs'),
                 (r'^(posix|mq$|mq[A-Z]|pthread)', 'posix/mq'),
                 (r'^(select|sel[A-Z]|pipe$|pipe[A-Z]|ty[A-Z]|ios|io[A-Z])', 'ios/pipe/ty/select'),
                 (r'^(sym[A-Z]|symTbl)', 'symTbl'),
                 (r'^(exc|Exc)', 'exc'),
                 (r'^(task[A-Z]|task$)', 'task'),
                 (r'^(sem[A-Z]|sem$)', 'sem')]:
    print(f"{lbl:24s} {cnt_pat(pat)}")

print("\n=== 5. конфиги памяти ===")
for va in (0x3012929C, 0x301292A0, 0x301292A4, 0x301292A8):
    o = va - BASE
    print(f"{va:08X}: {words[o//4]:08X}")

print("\n=== 6. версия BalongV через ссылки ===")
off = d.find(b'BalongV%03dR%03dC%02dSPC%03dB%03d')
print("string payload off:", hex(off) if off >= 0 else None)
if off >= 0:
    va = off + BASE
    refs = [i*4 + BASE for i, w in enumerate(words) if w == va]
    print("refs:", [hex(r) for r in refs[:6]])
    for r in refs[:3]:
        inside = [(a, n) for a, n, m, c in func_rows if a <= r]
        print("  in/after:", inside[-1] if inside else None)

print("\n=== 7. shell help-таблица ===")
off = d.find(b'help                           Print this list')
va = off + BASE
refs = [i * 4 for i, w in enumerate(words) if w == va]
print("string VA", hex(va), "ref@", [hex(r + BASE) for r in refs[:4]])
if refs:
    r0 = refs[0] // 4
    for k in range(-1, 46):
        if 0 <= r0 + k < wc:
            w = words[r0 + k]
            s = va_str(w)
            print(f"  +{k:3d} {w:08X} {s[:70] if s else ''}")

print("\n=== 8. BSP log-команды ===")
off = d.find(b'BSP_SetLogLevel\x00')
va = off + BASE
refs = [i * 4 for i, w in enumerate(words) if w == va]
print("name VA", hex(va), "refs:", [hex(r + BASE) for r in refs[:6]])
if refs:
    r0 = refs[0] // 4
    addr_by = {a: n for a, n, m, c in func_rows}
    for k in range(-6, 8):
        if 0 <= r0 + k < wc:
            w = words[r0 + k]
            s = va_str(w, 36)
            fn = addr_by.get(w)
            print(f"  +{k:3d} {w:08X} str={s!r} func={fn}")

print("\n=== 9. таблица продуктов: дамп региона ===")
lo, hi = 0x3012F9C0 - BASE, 0x30130060 - BASE
for o in range(lo, hi, 16):
    va = o + BASE
    ann = []
    for k in range(0, 16, 4):
        w = words[(o + k) // 4]
        s = va_str(w)
        if s: ann.append(f"+{k}:{s[:22]}")
        elif BASE <= w < 0x301B018C: ann.append(f"+{k}->{w:08X}")
    asc = "".join(chr(c) if 32 <= c < 127 else "." for c in d[o:o+16])
    print(f"{va:08X}: " + " ".join(f"{words[(o+k)//4]:08X}" for k in range(0, 16, 4)) + f" |{asc}| " + " ".join(ann))

print("\n=== 10. data: группы ===")
groups = collections.Counter()
for a, n, m, c in func_rows:
    mm = re.match(r'^([A-Za-z][A-Za-z0-9]{1,15})', n)
    groups[mm.group(1) if mm else n] += 1
for k, c in groups.most_common(28):
    print(f"  {k:18s} {c}")

print("\n=== 11. data: топ fan-in ===")
data_rows = [(a, n, c) for a, n, m, c in func_rows if m == 'data']
for a, n, c in sorted(data_rows, key=lambda x: -x[2])[:20]:
    print(f"  {a:08X} {n:36s} callers={c}")

print("\n=== 12. boot params refs ===")
off = d.find(b'boot device')
va = off + BASE
for ref in [i*4 for i, w in enumerate(words) if w == va][:2]:
    o = ref
    print(f"-- таблица @ {o+BASE:08X}:")
    for k in range(-4, 26):
        oo = o + k*4
        if 0 <= oo < wc*4 - 3:
            w = words[oo//4]
            s = va_str(w, 42)
            print(f"   {(oo//4)*4+BASE:08X}: {w:08X} {s if s else ''}")
