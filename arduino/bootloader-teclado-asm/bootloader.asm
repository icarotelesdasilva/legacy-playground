[BITS 16]
[ORG 0x7c00]

loopa:
MOV AH, 0x00
INT 0x16  


MOV AH, 0x0E
INT 0x10 

JMP loopa

times 510 - ($ - $$) db 0
dw 0xAA55
