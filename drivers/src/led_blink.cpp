#include "led_blink.hpp"


Blinker::Blinker() {
    std::cout << "Blinker initialized." << std::endl;
}

void Blinker::blink_demo() {

    for(int i =0; i < 5; i++) {
        led_ON();
        vTaskDelay(1000);
        led_OFF();
    }
   
}

void Blinker::led_ON() {
    gpio_set_level(BLINK_GPIO, 0);
}

void Blinker::led_OFF() {
    gpio_set_level(BLINK_GPIO, 1);
}