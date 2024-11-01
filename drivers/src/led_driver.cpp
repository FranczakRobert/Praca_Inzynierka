#include "led_driver.hpp"

Led::Led(){
    init();
}

Led::~Led() {
    deinit();
}

ErrorCode Led::start()
{
    for(int i = 0; i < 2; i++) {
        gpio_set_level(GPIO_ESP_PIN_OUT,1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(GPIO_ESP_PIN_OUT,0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    return E_OK;
}

ErrorCode Led::turn_led_wifi_on()
{
    gpio_set_level(GPIO_ESP_PIN_OUT,static_cast<uint32_t>(LedState::ON));
    return E_OK;
}

ErrorCode Led::turn_led_wifi_off()
{
    gpio_set_level(GPIO_ESP_PIN_OUT,static_cast<uint32_t>(LedState::OFF));
    return E_OK;
}

ErrorCode Led::init() {
    gpio_set_direction(GPIO_ESP_PIN_OUT,GPIO_MODE_OUTPUT);
    return E_OK;
}

ErrorCode Led::deinit() {
    gpio_reset_pin(GPIO_ESP_PIN_OUT);
    return E_OK;
}
