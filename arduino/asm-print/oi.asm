
section .data
 msg db 'oi', 10 

section .text

global _start

_start:

MOV RAX, 1
MOV RDI, 1
MOV RSI, msg
MOV RDX, 3
syscall

; e a parte que acabou abaixo escrevi comentario so para lembrar.

MOV RAX, 60
MOV RDI, 0
syscall