# Makefile
# Nick Michael

compile: hello.asm
	nasm -f elf64 $< -o $(<:.asm=.o)
	ld -s $(<:.asm=.o) -o hello.x

clean:
	rm *.o *.x
