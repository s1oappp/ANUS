# GNU-toolchain путь сборки (экспериментальный).
# Авторитетный верифицированный путь: python make_rebuild.py build (Keystone) — см. ../docs/BUILD.md
# Требует arm-none-eabi-as / arm-none-eabi-objcopy в PATH.

AS      ?= arm-none-eabi-as
OBJCOPY ?= arm-none-eabi-objcopy
AFLAGS  ?= -march=armv7-a -marm

all: usblsafe-327x.bin

header.bin: header.s
	$(AS) $(AFLAGS) -o header.o $<
	$(OBJCOPY) -O binary header.o header.bin

stub.bin: stub.s
	$(AS) $(AFLAGS) -o stub.o $<
	$(OBJCOPY) -O binary stub.o stub.bin

body.bin: body.s
	$(AS) $(AFLAGS) -o body.o $<
	$(OBJCOPY) -O binary body.o body.bin

usblsafe-327x.bin: header.bin stub.bin body.bin
	cat header.bin stub.bin body.bin > $@
	sha256sum -c expected.sha256

clean:
	rm -f header.bin stub.bin body.bin header.o stub.o body.o out/usblsafe-327x.bin

.PHONY: all clean
