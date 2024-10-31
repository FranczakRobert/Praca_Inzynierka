#include "driver/gpio.h"
#include "led_driver.hpp"

#define GPIO_ESP_PIN_OUT GPIO_NUM_2 

const static char* TAG = "LED";

LED::LED(){
    init();
}

LED::~LED() {
    deinit();
}

int LED::start()
{
    for(int i = 0; i < 2; i++) {
        gpio_set_level(GPIO_ESP_PIN_OUT,1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(GPIO_ESP_PIN_OUT,0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    return 0;
}

int LED::init() {
    gpio_set_direction(GPIO_ESP_PIN_OUT,GPIO_MODE_OUTPUT);
    return 0;
}

int LED::deinit() {
    gpio_reset_pin(GPIO_ESP_PIN_OUT);
    return 0;
}
