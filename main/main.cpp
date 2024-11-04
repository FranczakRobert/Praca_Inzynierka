
#include <iostream>
#include "wifi_driver.hpp"
#include "led_driver.hpp"
#include "server.hpp"

extern "C" void app_main(void) {
    Led led;
    WifiDriver wifi = WifiDriver(led);
    Server server = Server(led);
    
    wifi.start();
    server.start_webserver();


    while(1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS); 
    }
}
