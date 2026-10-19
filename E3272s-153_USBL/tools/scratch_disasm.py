import struct, re, csv, sys
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM

PATH = r".zwork\attachments\5fe2b94a-8ba3-4f1a-9db2-6e9725a63641\usblsafe-327x.bin"
d = open(PATH, "rb").read()
n = len(d)
HDR = 0x3C0
BASE = 0x30004000
IMG_END_VA = BASE + (n - HDR)
CODE_END_VA = 0x3012E06B  # strings begin here ("0ARM RealView PBX-A9" at file 0x12A42B)

strmap = {}
for m in re.finditer(rb"[\x20-\x7e]{2,}\x00", d):
    strmap[m.start() - HDR + BASE] = m.group()[:-1].decode("ascii", "replace")

syms = {}
with open("symbols.csv", encoding="utf-8") as f:
    r = csv.reader(f); next(r)
    for va, name, t, node in r:
        v = int(va, 16)
        syms.setdefault(v, name)

codevas = sorted(v for v in syms if BASE <= v < CODE_END_VA)
print("code symbols:", len(codevas))

# function boundaries
starts = codevas
ends = {}
for i, v in enumerate(starts):
    ends[v] = starts[i + 1] if i + 1 < len(starts) else IMG_END_VA

md = Cs(CS_ARCH_ARM, CS_MODE_ARM)
md.detail = True

def word_at(va):
    off = va - BASE + HDR
    if 0 <= off <= n - 4:
        return struct.unpack_from("<I", d, off)[0]
    return None

def ann_target(t):
    if t in syms: return syms[t]
    if t in strmap: s = strmap[t]; return '"%s"' % (s[:48])
    return None

out = open("disasm_full.asm", "w", encoding="utf-8", errors="replace")
w = out.write
w("; Full linear disassembly of usblsafe-327x.bin payload\n")
w("; Image: Huawei USBL (burn/USB-loader) for E3272s-153, VxWorks 6.8, ARMv7-A\n")
w("; VA = file_off - 0x3C0 + 0x30004000 ; %d functions (symbol table)\n" % len(starts))
w("; mnemonic <addr> annotation scheme: branches annotated with symbol/string when resolvable\n\n")

import time
t0 = time.time()
total_ins = 0
for i, fv in enumerate(starts):
    name = syms.get(fv, "")
    fend = ends[fv]
    w("\n;==================== FUNCTION %s @ 0x%08X (size 0x%X) ====================\n" % (name, fv, fend - fv))
    off = fv - BASE + HDR
    code = d[off: off + (fend - fv)]
    try:
        insns = list(md.disasm(code, fv))
    except Exception as e:
        w("; disasm error %s\n" % e); continue
    ii = 0
    while ii < len(insns):
        ins = insns[ii]
        total_ins += 1
        line = "%08X  %-8s %s" % (ins.address, ins.mnemonic, ins.op_str)
        anns = []
        # branch target
        if ins.group(0) is not None and ins.mnemonic.startswith(("b", "bl")):
            for op in ins.operands:
                if op.type == 2:  # IMM
                    t = op.imm
                    a = ann_target(t)
                    if a: anns.append("-> " + a)
        # ldr literal
        if ins.mnemonic == "ldr" and "[pc" in ins.op_str:
            try:
                import re as _re
                m = _re.search(r"\[pc, #(-?\d+)\]", ins.op_str)
                imm = int(m.group(1)) if m else 0
                lit = (ins.address + 8 + imm) & ~3
                wv = word_at(lit)
                if wv is not None:
                    a = ann_target(wv)
                    if a: anns.append("lit@%08X=%s" % (lit, a))
                    else: anns.append("lit@%08X=0x%08X" % (lit, wv))
            except Exception:
                pass
        if anns: line += "   ; " + "  ".join(anns)
        w(line + "\n")
        ii += 1
    if i % 400 == 0:
        print("progress: func %d/%d  %s  (%.0fs)" % (i, len(starts), name, time.time() - t0), flush=True)

out.close()
print("total instructions:", total_ins, " time:", round(time.time() - t0, 1), "s")

# functions.csv
with open("functions.csv", "w", newline="", encoding="utf-8") as f:
    wcsv = csv.writer(f)
    wcsv.writerow(["va_hex", "end_va_hex", "size", "name"])
    for v in starts:
        wcsv.writerow([f"{v:08X}", f"{ends[v]:08X}", ends[v] - v, syms.get(v, "")])
print("functions.csv written")

# stub disassembly (header stub at file 0x54..0x3C0, VA 0x2FFE4000)
stub = d[0x54:HDR]
with open("disasm_stub.asm", "w", encoding="utf-8") as f:
    f.write("; USBL first-stage stub, VA 0x2FFE4000 (file 0x54-0x3C0)\n")
    for ins in md.disasm(stub, 0x2FFE4000):
        f.write("%08X  %-8s %s\n" % (ins.address, ins.mnemonic, ins.op_str))
print("stub disasm written")
