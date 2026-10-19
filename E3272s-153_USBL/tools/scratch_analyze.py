import collections, math, re, struct, sys

PATH = r".zwork\attachments\5fe2b94a-8ba3-4f1a-9db2-6e9725a63641\usblsafe-327x.bin"
d = open(PATH, "rb").read()
n = len(d)
print("size:", n, hex(n))

def hx(b): return b.hex(" ")
print("first 64 :", hx(d[:64]))
print("last  64 :", hx(d[-64:]))

def ent(b):
    if not b: return 0.0
    c = collections.Counter(b); ln = len(b)
    return -sum(v/ln*math.log2(v/ln) for v in c.values())

print("\n--- entropy per 64K block ---")
for off in range(0, n, 0x10000):
    b = d[off:off+0x10000]
    z = b.count(0); f = b.count(0xFF)
    print(f"{off:08X} ent={ent(b):.2f} zero={z*100//len(b):3d}% ff={f*100//len(b):3d}%")

print("\n--- signature scan ---")
sigs = [
    (b"MZ", "PE/DOS header"),
    (b"\x7fELF", "ELF"),
    (b"\x1f\x8b\x08", "gzip"),
    (b"\xfd7zXZ\x00", "xz"),
    (b"\x28\xb5\x2f\xfd", "zstd"),
    (b"BZh", "bzip2"),
    (b"\x04\x22\x4d\x18", "lz4"),
    (b"PK\x03\x04", "zip"),
    (b"7z\xbc\xaf\x27\x1c", "7z"),
    (b"Rar!", "rar"),
    (b"hsqs", "squashfs(BE-LE)"),
    (b"qshs", "squashfs(LE-BE)"),
    (b"\x19\x85", "jffs2 node(maybe)"),
    (b"UBI#", "UBI"),
    (b"\x27\x05\x19\x56", "uImage"),
    (b"HDR0", "TRX header"),
    (b"CD001", "ISO9660"),
    (b"\x89PNG", "PNG"),
    (b"\xff\xd8\xff", "JPEG"),
    (b"eGon", "Allwinner eGON"),
    (b"BOOT", "BOOT string"),
    (b"\xd0\x0d\xfe\xed", "DTB"),
    (b"\xea\xff\xff\xea", "ARM jump vector?"),
    (b"STM2", "STM string"),
]
for sig, name in sigs:
    pos = []
    start = 0
    while True:
        i = d.find(sig, start)
        if i < 0 or len(pos) >= 8: break
        pos.append(i); start = i + 1
    if pos:
        print(f"{name}: {[hex(p) for p in pos]}")

print("\n--- keyword scan ---")
kw = [b"Copyright", b"GCC", b"GNU", b"FreeRTOS", b"RT-Thread", b"ThreadX", b"VxWorks",
      b"Zephyr", b" NuttX", b"uCos", b"ucos", b"ChibiOS", b"linux", b"Linux", b"Build",
      b"Version", b"version", b"Ver ", b"STM32", b"GD32", b"CH32", b"AT32", b"ESP32",
      b"ESP8266", b"ARM", b"thumb", b"Cortex", b"Keil", b"IAR", b"MDK", b"RealView",
      b"www.", b"http://", b"https://", b"usb", b"USB", b"Lsafe", b"LSAFE", b"Safe", b"SAFE"]
for k in kw:
    idx = []
    start = 0
    while True:
        i = d.find(k, start)
        if i < 0 or len(idx) >= 6: break
        idx.append(i); start = i + 1
    if idx:
        print(f"{k.decode(errors='replace')}: {[hex(i) for i in idx]} ({d.count(k)} total)")

print("\n--- ASCII strings (len>=6), first 250 ---")
cnt = 0
for m in re.finditer(rb"[\x20-\x7e]{6,}", d):
    s = m.group().decode("ascii", "replace")
    print(f"{m.start():08X}: {s[:120]}")
    cnt += 1
    if cnt >= 250: break
print("...total printable-ascii runs:", sum(1 for _ in re.finditer(rb"[\x20-\x7e]{6,}", d)))

print("\n--- vector table guess (first 32 words as LE32) ---")
for i in range(0, 32, 4):
    w = struct.unpack("<I", d[i:i+4])[0]
    print(f"{i:08X}: {w:08X}")
