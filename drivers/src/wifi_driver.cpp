#include "wifi_driver.hpp"
#include "driver_abstract.hpp"

WifiDriver::WifiDriver() {
    init();
}

WifiDriver::~WifiDriver() {
    deinit();
}

int WifiDriver::init() {
    std::cout << "Wifi INIT" << std::endl;
    return 0;
}

int WifiDriver::deinit() {
    std::cout << "Wifi DEINIT" << std::endl;
    return 0;
}

int WifiDriver::start() {
    std::cout << "Wifi START" << std::endl;
    return 0;
}
