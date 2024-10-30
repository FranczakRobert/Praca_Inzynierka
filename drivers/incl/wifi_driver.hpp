#ifndef WIFI_HPP
#define WIFI_HPP

#include <iostream>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_log.h"
#include "driver_abstract.hpp"

class WifiDriver : public Driver {

    public:
    WifiDriver();
    ~WifiDriver();

    int start();


    private:
    int init();
    int deinit();
};

#endif // WIFI_HPP