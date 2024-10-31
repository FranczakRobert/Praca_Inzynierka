
#include <iostream>
#include "wifi_driver.hpp"


extern "C" void app_main(void) {

    WifiDriver *wifi = new WifiDriver();
    wifi->start();

    while(1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS); 
    }
    
    delete wifi;
}
