CP = cp
CC = i686-elf-gcc
LINKER = i686-elf-gcc
ASSEMBLER = i686-elf-as
GRUB = grub-mkrescue
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra
LFLAGS = -o myos.bin -ffreestanding -O2 -nostdlib -lgcc

default: lborowczak-kernel

lborowczak-kernel: myos.bin 
	$(GRUB) -o lborowczak-kernel.iso iso

myos.bin: linker.ld boot.o kernel.o
	$(LINKER) -T linker.ld -o myos.bin boot.o kernel.o $(LFLAGS)
	$(CP) myos.bin ./iso/boot/

boot.o: boot.s
	$(ASSEMBLER) boot.s -o boot.o

kernel.o: kernel.c
	$(CC) -c kernel.c -o kernel.o $(CFLAGS)

clean: 
	$(RM) lborowczak-kernel.iso myos.bin *.o *~ ./iso/boot/myos.bin
