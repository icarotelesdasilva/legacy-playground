#include "botao-includes.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define BOTAO_PINO GPIO_NUM_0

void inicializar_botao(void) {
    gpio_reset_pin(BOTAO_PINO);
    gpio_set_direction(BOTAO_PINO, GPIO_MODE_INPUT);
    gpio_set_pull_mode(BOTAO_PINO, GPIO_PULLUP_ONLY);
}

int ler_estado_botao(void) {
    return gpio_get_level(BOTAO_PINO);
}
