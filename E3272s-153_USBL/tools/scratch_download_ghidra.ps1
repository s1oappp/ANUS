$ErrorActionPreference = 'Continue'
$tools = Join-Path (Get-Location) 'tools'
New-Item -ItemType Directory -Force -Path $tools | Out-Null
$log = Join-Path $tools 'ghidra_dl.log'
function Log($m) { "$(Get-Date -Format o) $m" | Out-File -Append -FilePath $log -Encoding utf8 }

if (Test-Path "$tools\ghidra.zip") { Remove-Item "$tools\ghidra.zip" -Force }

$cands = @(
  'https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_11.4.2_build/ghidra_11.4.2_PUBLIC_20250710.zip',
  'https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_11.3.2_build/ghidra_11.3.2_PUBLIC_20250415.zip',
  'https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_11.3.1_build/ghidra_11.3.1_PUBLIC_20250219.zip'
)
$ok = $false
foreach ($u in $cands) {
  Log "trying $u"
  curl.exe -L --retry 2 -sS -o "$tools\ghidra.zip" $u
  if (Test-Path "$tools\ghidra.zip") {
    $sz = (Get-Item "$tools\ghidra.zip").Length
    Log "downloaded size=$sz"
    if ($sz -gt 100MB) { $ok = $true; break }
  }
}
if (-not $ok) { Log 'ALL ATTEMPTS FAILED'; exit 1 }

Log 'extracting'
tar.exe -xf "$tools\ghidra.zip" -C $tools
Log 'ALL DONE'
