PREFIX=riscv64-unknown-elf
CC=$(PREFIX)-gcc
OBJDUMP=$(PREFIX)-objdump

all: foo.S
	@$(CC) -g -Og -nostdlib -Tlink.ld -Iinclude $^ -o foo

disasm:
	@$(OBJDUMP) -xDt foo > foo.disasm
