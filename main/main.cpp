
#include <iostream>
#include "wifi_driver.hpp"
#include "led_driver.hpp"

extern "C" void app_main(void) {
    Led led;
    WifiDriver wifi = WifiDriver(led);
    
    wifi.start();

    while(1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS); 
    }
}
