bits 16
org 0x7C00

start:
    cli
    xor ax, ax
    mov ds, ax
    mov ss, ax
    mov sp, 0x7C00

    mov ax, 0x1000
    mov es, ax

    mov ah, 0x02        
    mov al, 2           
    mov ch, 0           
    mov cl, 2          
    mov dh, 0          
    mov dl, 0x00     
    mov bx, 0x0000      
    int 0x13
    jc disk_error

    xor ax, ax
    mov es, ax

    lgdt [gdt_descriptor]

    mov eax, cr0
    or eax, 1
    mov cr0, eax
    jmp CODE_SEG:init_pm

[BITS 32]
init_pm:
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov esp, 0x90000
    call kernel_main

hang:
    jmp hang

disk_error:
    mov ah, 0x0E
    mov al, 'E'
    int 0x10
    jmp $

gdt_start:
    dd 0x0
    dd 0x0

gdt_code:
    dw 0xFFFF 
    dw 0x0000 
    db 0x00
    db 10011010b
    db 11001111b
    db 0x00

gdt_data:
    dw 0xFFFF
    dw 0x0000
    db 0x00
    db 10010010b
    db 11001111b
    db 0x00

gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

kernel_main:
    call 0x10000 
    ret

TIMES 510 - ($ - $$) db 0
DW 0xAA55
