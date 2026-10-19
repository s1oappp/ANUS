# @category Analysis.USBL
# Ghidra pre-script: import VxWorks symbol table extracted from the firmware
import csv
from ghidra.program.model.symbol import SourceType
from ghidra.app.cmd.function import CreateFunctionCmd

CSV = r"C:\Users\soap\AppData\Roaming\AutoClaw-oversea-official\accounts\43596b82b66cb10bcf2908ca6ab065fa656083f061144b1f1ab751ad2d481b2c\projects\Default\symbols.csv"
CODE_END = 0x3012E06B

try:
    setAnalysisOption(currentProgram, "Decompiler Parameter ID", "false")
    setAnalysisOption(currentProgram, "Non-Returning Functions - Discovered", "false")
except Exception as e:
    print("option set failed: %s" % e)

prog = currentProgram
af = prog.getAddressFactory().getDefaultAddressSpace()
st = prog.getSymbolTable()
fm = prog.getFunctionManager()

rows = []
with open(CSV, "r") as f:
    rd = csv.reader(f)
    next(rd)
    for va, name, t, node in rd:
        rows.append((int(va, 16), name))
print("SYMBOLS_ROWS %d" % len(rows))

nlab = 0
nfun = 0
nfail = 0
for va, name in rows:
    a = af.getAddress(va)
    try:
        if st.getLabelAt(a, prog.getGlobalNamespace()) is None:
            st.createLabel(a, name, SourceType.USER_DEFINED)
            nlab += 1
    except Exception:
        pass
    if va < CODE_END and fm.getFunctionAt(a) is None:
        try:
            c = CreateFunctionCmd(name, a, None, SourceType.USER_DEFINED)
            if c.applyTo(prog, monitor):
                nfun += 1
            else:
                nfail += 1
        except Exception:
            nfail += 1
print("SYMBOLS_IMPORTED labels=%d functions=%d failed=%d" % (nlab, nfun, nfail))
