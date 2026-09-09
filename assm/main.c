#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char TAM[256];

void process(const char *all, FILE *file_exit) {
    char command[20];
    char registrator[20];
    int value;
    char clean_line[100];
    unsigned char opcode_end = 0;
    int registrator_valid = 1;

    strcpy(clean_line, all);
    clean_line[strcspn(clean_line, "\r\n")] = 0;

    if (strlen(clean_line) == 0 || clean_line[0] == ';') {
        return;
    }

    if (sscanf(clean_line, "%s %[^,], %d", command, registrator, &value) == 3) {
        if (strcmp(command, "go") == 0) {
            if (strcmp(registrator, "eax") == 0) opcode_end = 0xB8;
            else if (strcmp(registrator, "ecx") == 0) opcode_end = 0xB9;
            else if (strcmp(registrator, "edx") == 0) opcode_end = 0xBA;
            else if (strcmp(registrator, "ebx") == 0) opcode_end = 0xBB;
            else {
                printf("[Error] Invalid Register on Line: \"%s\"\n", clean_line);
                registrator_valid = 0;
            }

            if (registrator_valid) {
                printf("[Assembler] Processed: %s %s, %d -> Opcode: 0x%X\n", command, registrator, value, opcode_end);
                fwrite(&opcode_end, 1, 1, file_exit);
                fwrite(&value, sizeof(int), 1, file_exit);
            }
        } 
        else {
            printf("[Error] Unknown command on Line: \"%s\"\n", clean_line);
        }
    } 
    else {
        printf("[Warning] Line syntax not recognized: \"%s\"\n", clean_line);
    }
}

int main() {
    FILE *arquivo = fopen("file.icr", "r");
    if (arquivo == NULL) {
        fprintf(stderr, "Error: 'file.icr' file not found.\n");
        return -1;
    }

    FILE *file_exit = fopen("result.bin", "wb");
    if (file_exit == NULL) {
        fprintf(stderr, "Error: Could not create output binary file.\n");
        fclose(arquivo);
        return -1;
    }

    printf("Starting file sweep on 'file.icr'\n\n");

    while (fgets(TAM, sizeof(TAM), arquivo) != NULL) {
        process(TAM, file_exit);
    }

    fclose(arquivo);
    fclose(file_exit);

    printf("\nAssembly completed! 'result.bin' generated\n");
    return 0;
}
