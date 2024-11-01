#include "led_driver.hpp"

#define GPIO_ESP_PIN_OUT GPIO_NUM_2 
#define LED_ON  1
#define LED_OFF 0

const static char* TAG = "LED";

Led::Led(){
    init();
}

Led::~Led() {
    deinit();
}

int Led::start()
{
    for(int i = 0; i < 2; i++) {
        gpio_set_level(GPIO_ESP_PIN_OUT,1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(GPIO_ESP_PIN_OUT,0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    return 0;
}

int Led::turn_led_wifi_on()
{
    gpio_set_level(GPIO_ESP_PIN_OUT,LED_ON);
    return 0;
}

int Led::turn_led_wifi_off()
{
    gpio_set_level(GPIO_ESP_PIN_OUT,LED_OFF);
    return 0;
}

int Led::init() {
    gpio_set_direction(GPIO_ESP_PIN_OUT,GPIO_MODE_OUTPUT);
    return 0;
}

int Led::deinit() {
    gpio_reset_pin(GPIO_ESP_PIN_OUT);
    return 0;
}
