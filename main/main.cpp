
#include <iostream>
#include "wifi_driver.hpp"


extern "C" void app_main(void) {

    WifiDriver wifi = WifiDriver();
    wifi.start();
}
