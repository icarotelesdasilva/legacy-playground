ASM = nasm
LD = ld

all: os-image.bin

boot.bin: boot.asm
	$(ASM) -f bin $< -o $@

kernel.o: kernel.asm
	$(ASM) -f elf32 $< -o $@

kernel.bin: kernel.o linker.ld
	$(LD) -m elf_i386 -T linker.ld -o kernel.bin kernel.o --oformat binary

os-image.bin: boot.bin kernel.bin
	cat boot.bin kernel.bin > os-image.bin
	truncate -s 1474560 os-image.bin

run: os-image.bin
	qemu-system-i386 -drive format=raw,file=os-image.bin,if=floppy

clean:
	rm -f *.o *.bin
