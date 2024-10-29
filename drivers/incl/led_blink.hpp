#ifndef LED_BLINK_HPP
#define LED_BLINK_HPP
#include <iostream>
#include "driver/gpio.h"
#include "led_blink.hpp"

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define BLINK_GPIO GPIO_NUM_2

class Blinker {
public:
    Blinker();
    void blink_demo();

private:
    void led_ON();
    void led_OFF();
};

#endif // LED_BLINK_HPP
