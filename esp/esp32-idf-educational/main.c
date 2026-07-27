// Biblioteca padrão de entrada e saída (para funções básicas de texto)
#include <stdio.h> 

// Bibliotecas obrigatórias do FreeRTOS (Sistema Operacional do ESP32)
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Biblioteca de Logs do ESP-IDF (responsável pelas mensagens no terminal)
#include "esp_log.h"

/* NOSSAS MACROS (#define):
   Aqui criamos os atalhos para simplificar o código.
   O compilador vai substituir os nossos apelidos pelos comandos reais do ESP-IDF.
*/
// Atalho para o comando de Log do ESP-IDF (sem ponto e vírgula no final)
#define print(tag, texto) ESP_LOGI(tag, texto)

// Atalho para o comando de tempo do FreeRTOS
#define esperar(ms) vTaskDelay(pdMS_TO_TICKS(ms))


// Função principal do firmware (Não devolve nada e não recebe nada)
void app_main(void) 
{
    // Usa o nosso atalho 'print' para mandar uma mensagem de inicialização
    print("SISTEMA", "hello word"); 
    print("SISTEMA", "firmware vivo");

    /* LOOP INFINITO (while):
       Prende o processador aqui dentro para o programa não fechar.
       Isso evita que a função acabe e cause um Reset/Kernel Panic no chip.
    */
    while(1) { 
        // Avisa que o chip está ativo
        print("STATUS", "BIP");

        // Usa o nosso atalho 'esperar' para pausar por 3000 milissegundos (3 segundos)
        esperar(3000); 
    }

} // Fecha a função app_main
