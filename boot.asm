[BITS 16]
[ORG 0x7c00]

main:
    xor ax, ax
    mov ds, ax
    mov es, ax

    ; Imprime o 'o' inicial
    mov ah, 0x0E
    mov al, 'o'
    int 0x10

    ; --- LER O KERNEL DO DISCO ---
    mov bx, 0x1000     ; Destino: 0x1000
    mov ah, 0x02       
    mov al, 15         ; Lê 15 setores para garantir que config.o e kernel.o entrem
    mov ch, 0          
    mov cl, 2          
    mov dh, 0          
    int 0x13           
    jc erro_leitura    

    ; --- ENTRAR EM MODO PROTEGIDO (32 BITS) COM GDT ---
    cli                 ; Desativa interrupções de 16 bits
    lgdt [gdt_descriptor] ; Carrega a tabela GDT

    mov eax, cr0
    or eax, 1
    mov cr0, eax        ; Ativa o Modo Protegido

    ; Salto longo para limpar o pipeline do processador e carregar o segmento de código (0x08)
    jmp 0x08:init_32bit

erro_leitura:
    mov ah, 0x0E
    mov al, 'E'        
    int 0x10
loo_icaro:
    jmp loo_icaro

; --- CÓDIGO DE 32 BITS ---
[BITS 32]
init_32bit:
    ; Configura os registradores de segmento de dados com o seletor de dados da GDT (0x10)
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    ; Salta definitivamente para o endereço do seu kernel em C
    jmp 0x1000

; --- ESTRUTURA DA GDT ---
gdt_start:
    dd 0x0          ; Segmento nulo obrigatório (8 bytes)
    dd 0x0

gdt_code:           ; Segmento de Código (Base=0, Limite=0xfffff, Tipo=Código Executável/Leitura)
    dw 0xffff
    dw 0x0
    db 0x0
    db 10011010b
    db 11001111b
    db 0x0

gdt_data:           ; Segmento de Dados (Base=0, Limite=0xfffff, Tipo=Dados Leitura/Escrita)
    dw 0xffff
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0
gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start

times 510-($-$$) db 0
dw 0xaa55
