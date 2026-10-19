# build_gnu.ps1 — сборка через arm-none-eabi (экспериментальная; верификация по SHA-256 обязательна)
# Авторитетный путь: python .\make_rebuild.py build
$ErrorActionPreference = 'Stop'
$here = Split-Path -Parent $MyInvocation.MyCommand.Path
$orig = Join-Path $here '..\artifacts\usblsafe-327x.bin'

foreach ($t in @('header','stub','body')) {
  & arm-none-eabi-as -march=armv7-a -marm -o "$here\$t.o" "$here\$t.s"
  & arm-none-eabi-objcopy -O binary "$here\$t.o" "$here\$t.bin"
}

$bytes = [System.IO.File]::ReadAllBytes("$here\header.bin") +
         [System.IO.File]::ReadAllBytes("$here\stub.bin") +
         [System.IO.File]::ReadAllBytes("$here\body.bin")
$outp = Join-Path $here 'out'
New-Item -ItemType Directory -Force -Path $outp | Out-Null
[System.IO.File]::WriteAllBytes((Join-Path $outp 'usblsafe-327x.bin'), [byte[]]$bytes)

$sha = -join ((Get-FileHash (Join-Path $outp 'usblsafe-327x.bin') -Algorithm SHA256).Hash.ToLower() -split '')
$exp = (Get-Content (Join-Path $here 'expected.sha256')).Split(' ')[0]
Write-Output ("rebuilt : " + $bytes.Length + " " + $sha)
Write-Output ("expected: " + $exp)
if ($sha -eq $exp) { Write-Output 'MATCH' } else { Write-Output 'MISMATCH — сверьтесь с docs/BUILD.md §3' }
