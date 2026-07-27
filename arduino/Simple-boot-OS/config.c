// Ponteiro para a memória de vídeo VGA (Modo Texto)
volatile char *video_memory = (char*)0xB8000;

// Variável global para rastrear a posição atual do cursor na tela
int cursor_pos = 0;

void print_string(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            // Pula para a próxima linha
            // Cada linha tem 80 caracteres. Cada caractere usa 2 bytes (ASCII + Cor).
            // 80 * 2 = 160 bytes por linha.
            cursor_pos = ((cursor_pos / 160) + 1) * 160;
        } else {
            // Desenha o caractere na tela
            video_memory[cursor_pos++] = str[i];
            
            // Define a cor do caractere (0x07 = Texto branco com fundo preto)
            video_memory[cursor_pos++] = 0x07;
        }
    }
}
