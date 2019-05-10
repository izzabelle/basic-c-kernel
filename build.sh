#!/bin/bash
nasm -f elf32 kernel.asm -o k_asm.o
gcc -m32 -c kernel.c -o k_c.o
ld -m elf_i386 -T link.ld -o kernel.bin k_asm.o k_c.o
if [[ $1 == "--run" ]]; then
	qemu-system-i386 -kernel kernel.bin
fi