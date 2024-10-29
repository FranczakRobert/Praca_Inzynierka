
#include <iostream>

#include "led_blink.hpp"


extern "C" void app_main(void)
{
    Blinker* blinker = new Blinker();
    blinker->blink_demo();

    std::cout << "Hello Wordl" << std::endl;

    delete(blinker);
}
