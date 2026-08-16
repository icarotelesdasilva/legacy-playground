#include <stdio.h>
#include <string.h>

char TAM[256];

int main() {


FILE *arquivo = fopen("meu_arquivo", "r");

if (arquivo == NULL) {
    perror("Erro no fopen");
    return 1;
}

while(fgets(TAM, sizeof(TAM), arquivo) != NULL) {

if(strncmp(TAM, "imprimir", 8) == 0) {

printf("achei\n");

fclose(arquivo);

return 0;

}
}
}
