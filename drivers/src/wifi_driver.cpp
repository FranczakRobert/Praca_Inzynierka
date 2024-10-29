#include "wifi_driver.hpp"
#include "driver_abstract.hpp"

const char* TAG = "WifiDriver";


WifiDriver::WifiDriver() {
    init();
}

WifiDriver::~WifiDriver() {
    deinit();
}

int WifiDriver::init() {
    ESP_LOGI(TAG, "Initialized successfully");
    return 0;
}

int WifiDriver::deinit() {
    ESP_LOGI(TAG, "Initialized successfully");
    return 0;
}

int WifiDriver::start() {
    ESP_LOGI(TAG, "Start successfully");
    return 0;
}
