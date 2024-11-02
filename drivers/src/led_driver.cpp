#include "led_driver.hpp"

#include <thread>
#include "stdio.h"


Led::Led() : stopTask(false){
    init();
}

Led::~Led() {
    deinit();
}

ErrorCode Led::start()
{
    if (xTaskCreate(&Led::led_wifi_connecting_state_wrapper, "LED_Connecting_State", 2048, this, 1, NULL) == pdPASS) {
        return E_OK;
    }
    return E_TASK_CREATE_ERROR;
}

ErrorCode Led::stop()
{
    stopTask = true;

    if(true == stopTask) {
        return E_OK;
    }

    return E_TSK_STOP_ERROR;
}

ErrorCode Led::turn_led_wifi_on()
{
    if(ESP_ERR_INVALID_ARG == gpio_set_level(GPIO_ESP_PIN_OUT,static_cast<uint32_t>(LedState::ON))) {
        return LED_GPIO_STATE_ERROR;
    }
    return E_OK;
}

ErrorCode Led::turn_led_wifi_off()
{
    if(ESP_ERR_INVALID_ARG == gpio_set_level(GPIO_ESP_PIN_OUT,static_cast<uint32_t>(LedState::OFF))) {
        return LED_GPIO_STATE_ERROR;
    }
    return E_OK;
}

ErrorCode Led::led_wifi_connecting_state()
{   
   while (!stopTask)
    {
        gpio_set_level(GPIO_ESP_PIN_OUT, static_cast<uint32_t>(LedState::ON));
        vTaskDelay(500 / portTICK_PERIOD_MS);
        gpio_set_level(GPIO_ESP_PIN_OUT, static_cast<uint32_t>(LedState::OFF));
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
    gpio_set_level(GPIO_ESP_PIN_OUT, static_cast<uint32_t>(LedState::OFF));

    return E_OK;
}

ErrorCode Led::init() {
    if(ESP_ERR_INVALID_ARG == gpio_set_direction(GPIO_ESP_PIN_OUT,GPIO_MODE_OUTPUT)) {
        return LED_GPIO_STATE_ERROR;
    }
    return E_OK;
}

ErrorCode Led::deinit() {
    gpio_reset_pin(GPIO_ESP_PIN_OUT);
    return E_OK;
}

void Led::led_wifi_connecting_state_wrapper(void* _this) {
    static_cast<Led*>(_this)->led_wifi_connecting_state();
    vTaskDelete(NULL);
}
