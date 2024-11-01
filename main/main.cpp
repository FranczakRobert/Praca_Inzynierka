
#include <iostream>
#include "wifi_driver.hpp"
#include "led_driver.hpp"

extern "C" void app_main(void) {
    Led *led = new Led();
    WifiDriver *wifi = new WifiDriver(led);
    
    wifi->start();

    while(1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS); 
    }
    delete wifi;
    delete led;
}
