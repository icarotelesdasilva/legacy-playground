#include <stdio.h>
#include "freertos/FreeRTOS.h"  // Obrigatório para o sistema de tarefas
#include "freertos/task.h"      // Obrigatório para a função vTaskDelay (o delay do ESP32)
#include "driver/gpio.h"        // Obrigatório para controlar os pinos do ESP32
#include "led-config.h"        // Obrigatório para a função de configuração do LED

void app_main(void) {
    config_led(); // Configura o LED

    while (1) {
        gpio_set_level(LED_PIN, 1); // Liga o LED
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Espera por 1 segundo
        gpio_set_level(LED_PIN, 0); // Desliga o LED
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Espera por 1 segundo
    }
}

// um firmware basico de led de testes.