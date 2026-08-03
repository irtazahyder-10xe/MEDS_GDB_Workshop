PREFIX=riscv64-unknown-elf
CC=$(PREFIX)-gcc

all: bubble_sort.S
	@$(CC) -g -Og -nostdlib -Tlink.ld -Iinclude $^ -o bubble_sort
