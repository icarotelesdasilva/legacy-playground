section .text
    global _start

_start:

MOV RAX, 60
MOV RDI, 0
syscall 
