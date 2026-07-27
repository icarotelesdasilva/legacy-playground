#include "driver-botao.h" 
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#define tag "SYSTEM"

void app_main(void) {
   ESP_LOGW(tag, "Warning: This is a warning message.");
   ESP_LOGE(tag, "ERROR: This is an error message.");
    botao(); // Configura o botão
    while (1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS); 
    }


}