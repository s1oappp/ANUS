# @category Analysis.USBL
# Ghidra post-script: decompile every function to one C file
from ghidra.app.decompiler import DecompInterface, DecompileOptions
from ghidra.util.task import ConsoleTaskMonitor
import codecs

OUT = r"C:\Users\soap\AppData\Roaming\AutoClaw-oversea-official\accounts\43596b82b66cb10bcf2908ca6ab065fa656083f061144b1f1ab751ad2d481b2c\projects\Default\decompiled_all.c"

fm = currentProgram.getFunctionManager()
di = DecompInterface()
di.setOptions(DecompileOptions())
di.openProgram(currentProgram)
mon = ConsoleTaskMonitor()
total = fm.getFunctionCount()
print("DECOMPILING %d functions" % total)

i = 0
fail = 0
out = codecs.open(OUT, "w", "utf-8")
out.write("/* Full Ghidra decompilation of usblsafe-327x.bin (Huawei USBL, VxWorks 6.8)\n")
out.write(" * Image base 0x30004000, symbols from embedded VxWorks symbol table. */\n\n")
for f in fm.getFunctions(True):
    if mon.isCancelled():
        out.write("/* CANCELLED */\n")
        break
    res = di.decompileFunction(f, 60, mon)
    i += 1
    if i % 200 == 0:
        print("DECOMP_PROGRESS %d / %d" % (i, total))
    out.write("/* ==== %s @ 0x%08X ==== */\n" % (f.getName(), f.getEntryPoint().getOffset()))
    if res.decompileCompleted():
        out.write(res.getDecompiledFunction().getC())
    else:
        fail += 1
        out.write("/* decompile failed: %s */\n" % res.getErrorMessage())
    out.write("\n\n")
out.close()
print("DECOMPILE_DONE functions=%d failed=%d" % (i, fail))
