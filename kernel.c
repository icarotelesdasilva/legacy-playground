// Declara para o compilador que essa função existe em outro arquivo (config.c)
void print_string(char *str);

void main() {
    print_string("ola meu nome e icr\n");
    print_string("e esse e meu kernel gerenciando apenas print simples.");
    
    // Loop infinito para o kernel não travar ou tentar fechar
    while(1); 
}
