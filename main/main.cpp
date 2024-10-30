
#include <iostream>
#include "wifi_driver.hpp"


extern "C" void app_main(void) {

    Driver *wifi = new WifiDriver();
    wifi->start();

    delete wifi;
}
