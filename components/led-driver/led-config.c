#include "led-config.h"
#include "driver/gpio.h"
#include "esp_log.h"

void config_led(void) {

gpio_reset_pin(GPIO_NUM_2);
gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);
gpio_set_level(GPIO_NUM_2, 0);
ESP_LOGI("LED", "LED configurado no pino GPIO çed padrao 2");

}

