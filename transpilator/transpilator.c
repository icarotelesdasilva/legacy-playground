#include "stdio.h"
#include "stdlib.h"
#include "string.h"


char TAM[256];

int main(void) {

FILE *arquivo = fopen("arquivo-test", "r");


if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir arquivo.\n");
        return -1;
    }

while (fgets(TAM, sizeof(TAM), arquivo) != NULL) {
        TAM[strcspn(TAM, "\r\n")] = '\0';
}
    printf("Lido limpo: [%s]\n", TAM);
if (strncmp(TAM, "imprimir", 8) == 0) {
        char *conteudo = TAM + 8;

        while (*conteudo == ' ' || *conteudo == '(') {
            conteudo++;
        }
printf("printf(%s\n", conteudo); // Já que o conteúdo já tem o ');' no final do seu teste
}
    fclose(arquivo);
    return 0;
}
