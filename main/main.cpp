
#include <iostream>
#include "wifi_driver.hpp"


int main(void) {
    
    Driver* wifi = new WifiDriver();
    wifi->start();
    
    delete wifi;
    
    return 0;
}
