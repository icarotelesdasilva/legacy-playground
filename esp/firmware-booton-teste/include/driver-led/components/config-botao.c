#include "driver-botao.h" // Atualizado para o nome correto do arquivo
#include "driver/gpio.h"


void botao(void) {

gpio_reset_pin(GPIO_NUM_0);

gpio_set_direction(GPIO_NUM_0, GPIO_MODE_INPUT);

gpio_set_pull_mode(GPIO_NUM_0, GPIO_PULLUP_ONLY);

}