[BITS 32]
[GLOBAL _start]
[GLOBAL kernel_main]

_start:
kernel_main:
    mov eax, 0xC0FFEE
    mov ebx, 0xDEADBEEF
.loop:
    hlt
    jmp .loop
