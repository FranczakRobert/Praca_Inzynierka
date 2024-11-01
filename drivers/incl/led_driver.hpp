#ifndef LED_DRIVER_HPP
#define LED_DRIVER_HPP

#include "driver_abstract.hpp"
#include "driver/gpio.h"

class Led : public Driver {
    public:
    Led();
    ~Led();
    int start();
    int turn_led_wifi_on();
    int turn_led_wifi_off();

    private:
    int init();
    int deinit();
};

#endif 