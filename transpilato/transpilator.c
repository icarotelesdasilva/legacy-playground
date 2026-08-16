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
if (strncmp(TAM, "imprimir", 8) == 0) {
            
            char *inicio_aspas = strchr(TAM, '"');
            
            if (inicio_aspas != NULL) {
                inicio_aspas++; 
                
                char *fim_aspas = strchr(inicio_aspas, '"');
                
                if (fim_aspas != NULL) {
         
                    *fim_aspas = '\0';
                    
         
                    printf("%s\n", inicio_aspas);
}
}
}
}
}
