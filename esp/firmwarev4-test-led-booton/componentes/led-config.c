#include "led-arqui.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define LED_PINO GPIO_NUM_2 // Altere para o pino real do seu LED se não for o GPIO 2

void inicializar_led(void) {
    gpio_reset_pin(LED_PINO);
    gpio_set_direction(LED_PINO, GPIO_MODE_OUTPUT);
}

void controlar_led(int estado) {
    gpio_set_level(LED_PINO, estado);
}
