#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "botao-includes.h"
#include "led-arqui.h"

void app_main(void) {
    inicializar_botao();
    inicializar_led();

    while(1) {
        // Se o botão for pressionado (retorna 0 por causa do pull-up)
        if (ler_estado_botao() == 0) {
            controlar_led(1); // Liga o LED
        } else {
            controlar_led(0); // Desliga o LED
        }
        vTaskDelay(pdMS_TO_TICKS(50)); // Delay para o watchdog
    }
}
