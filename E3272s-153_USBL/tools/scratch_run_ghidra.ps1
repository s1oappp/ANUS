$ErrorActionPreference = 'Continue'
$root = Get-Location
$tools = Join-Path $root 'tools'
$logf = Join-Path $tools 'ghidra_run.log'
# sandbox env fixes: Ghidra launch.bat requires APPDATA etc.
$env:APPDATA = 'C:\Users\soap\AppData\Roaming'
$env:LOCALAPPDATA = 'C:\Users\soap\AppData\Local'
$env:TEMP = 'C:\Users\soap\AppData\Local\Temp'
$env:TMP = $env:TEMP
$env:USERPROFILE = 'C:\Users\soap'
$env:HOMEDRIVE = 'C:'
$env:HOMEPATH = '\Users\soap'
$env:SystemRoot = 'C:\Windows'
$env:windir = 'C:\Windows'
$env:ComSpec = 'C:\Windows\system32\cmd.exe'
$env:SystemDrive = 'C:'
$env:PATHEXT = '.COM;.EXE;.BAT;.CMD;.VBS;.VBE;.JS;.JSE;.WSF;.WSH;.MSC'
$env:PROCESSOR_ARCHITECTURE = 'AMD64'
$env:COMPUTERNAME = 'PC'
$env:USERNAME = 'soap'
Log ("env SystemRoot=$env:SystemRoot APPDATA=$env:APPDATA JAVA_HOME=$env:JAVA_HOME")
function Log($m) { "$(Get-Date -Format o) $m" | Out-File -Append -FilePath $logf -Encoding utf8; Write-Output $m }

$gdir = Get-ChildItem $tools, (Join-Path $tools 'ghx') -Directory -ErrorAction SilentlyContinue | Where-Object { $_.Name -like 'ghidra_*' -and (Test-Path (Join-Path $_.FullName 'Ghidra\application.properties')) } | Select-Object -First 1
$jdk  = Get-ChildItem $tools -Directory | Where-Object { $_.Name -like 'jdk*' } | Select-Object -First 1
if (-not $gdir) { Log 'GHIDRA DIR NOT FOUND'; exit 1 }
if (-not $jdk)  { Log 'JDK DIR NOT FOUND'; exit 1 }
$jbin = Join-Path $jdk.FullName 'bin'
$env:JAVA_HOME = $jdk.FullName
$env:PATH = "$jbin;$env:PATH"
Log ("ghidra: " + $gdir.FullName)
Log ("jdk: " + $jdk.FullName)
Log ("java: " + ((& (Join-Path $jbin 'java.exe') -version 2>&1 | Out-String) -replace "\r?\n", ' '))

$hl   = Join-Path $gdir.FullName 'support\analyzeHeadless.bat'
$proj = Join-Path $root 'ghidra_proj'
New-Item -ItemType Directory -Force -Path $proj | Out-Null
$bin  = Join-Path $root 'usbl_payload_30004000.bin'
$sp   = Join-Path $root 'ghidra_scripts'

$baseArgs = @($proj, 'usbl', '-import', $bin, '-loader', 'BinaryLoader', '-loader-baseAddr', '0x30004000',
              '-scriptPath', $sp, '-preScript', 'import_symbols.py', '-postScript', 'decompile_all.py',
              '-analysisTimeoutPerFile', '5400')

Log 'attempt 1: ARM:LE:32:v7'
& $hl @baseArgs -processor 'ARM:LE:32:v7' 2>&1 | Tee-Object -FilePath $logf -Append
if ($LASTEXITCODE -eq 0) { Log 'SUCCESS v7'; exit 0 }

Log 'attempt 2: ARM:LE:32:v5t'
& $hl @baseArgs -processor 'ARM:LE:32:v5t' 2>&1 | Tee-Object -FilePath $logf -Append
if ($LASTEXITCODE -eq 0) { Log 'SUCCESS v5t'; exit 0 }

Log 'attempt 3: no processor override'
& $hl @baseArgs 2>&1 | Tee-Object -FilePath $logf -Append
Log ("final exit: " + $LASTEXITCODE)
