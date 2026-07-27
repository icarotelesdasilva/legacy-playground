[BITS 16]
[ORG 0x7c00]

start:
    MOV AH, 0x0E
    MOV AL, 'o'
    INT 0x10

    MOV AL, 'i'
    INT 0x10

loop_Icr:          ; 
    JMP loop_Icr   ; 

times 510-($-$$) db 0
dw 0xaa55
