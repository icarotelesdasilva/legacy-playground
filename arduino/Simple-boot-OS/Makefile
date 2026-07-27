all: os_disk.img

boot.bin: boot.asm
	nasm -f bin boot.asm -o boot.bin

kernel.o: kernel.c
	gcc -m32 -c kernel.c -o kernel.o -ffreestanding -O2 -fno-pie -fno-stack-protector

config.o: config.c
	gcc -m32 -c config.c -o config.o -ffreestanding -O2 -fno-pie -fno-stack-protector

kernel.bin: kernel.o config.o linker.ld
	ld -m elf_i386 -T linker.ld kernel.o config.o -o kernel.bin

os_disk.img: boot.bin kernel.bin
	cat boot.bin kernel.bin > os_disk.img
	# Expande o arquivo para garantir que tenha pelo menos 32KB (64 setores)
	dd if=/dev/zero bs=512 count=64 >> os_disk.img 2>/dev/null
	@echo "Sucesso! Imagem os_disk.img criada e expandida."

clean:
	rm -f *.o *.bin *.img
