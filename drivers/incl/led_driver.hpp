#ifndef LED_DRIVER_HPP
#define LED_DRIVER_HPP

#include "driver_abstract.hpp"
#include "driver/gpio.h"

enum class LedState {
    ON = 1,
    OFF = 0
};

class Led : public Driver {
    public:
    Led();
    ~Led();
    ErrorCode start();
    ErrorCode turn_led_wifi_on();
    ErrorCode turn_led_wifi_off();

    private:
    static constexpr gpio_num_t GPIO_ESP_PIN_OUT = GPIO_NUM_2;
    static constexpr char TAG[] = "LED";

    ErrorCode init();
    ErrorCode deinit();
};

#endif 