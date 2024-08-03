#include "driver/gpio.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define PIR_PIN 13
static const char *TAG = "PIR_TEST";

void app_main() {
    gpio_config_t io_conf = {.intr_type = GPIO_INTR_DISABLE,  // No interrupt for testing
                             .mode = GPIO_MODE_INPUT,
                             .pin_bit_mask = (1ULL << PIR_PIN),
                             .pull_down_en = GPIO_PULLDOWN_DISABLE,
                             .pull_up_en = GPIO_PULLUP_DISABLE};
    gpio_config(&io_conf);

    while (1) {
        int pir_value = gpio_get_level(PIR_PIN);
        ESP_LOGI(TAG, "PIR sensor value: %d", pir_value);
        vTaskDelay(pdMS_TO_TICKS(100));  // Check the sensor every 100ms
    }
}