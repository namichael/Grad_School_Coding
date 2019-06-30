;Nick Michael
;Hello World Assembly Example

section .data
    hello db	"Hello, World!",0xa
    msize equ	$ - hello

section .text
	global _start

_start:
	;Print Hello, World!
	mov		eax, 4			;sys_write
	mov		ebx, 1			;stdout
	mov		ecx, hello		;string to pass
	mov		edx, msize		;size of string
	int		0x80			;system call

	;Exit Process
	mov		eax, 1			;sys_exit
	int		0x80			;system call 
