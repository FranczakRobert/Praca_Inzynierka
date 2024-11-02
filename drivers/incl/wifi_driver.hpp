#ifndef WIFI_HPP
#define WIFI_HPP

#include <iostream>

#include <stdio.h> //for basic printf commands
#include <string.h> //for handling strings
#include "esp_wifi.h" //esp_wifi_init functions and wifi operations
#include "esp_event.h" //for wifi event
#include "nvs_flash.h" //non volatile storage
#include "lwip/err.h" //light weight ip packets error handling
#include "lwip/sys.h" //system applications for light weight ip apps

#include "driver_abstract.hpp"
#include "led_driver.hpp"
#include "driver_abstract.hpp"
#include "wifi_config.hpp"

class WifiDriver : public Driver {

    public:
    WifiDriver(Led& led);
    ~WifiDriver();

    ErrorCode start();

    private:
    int retry_num;
    Led wifi_led;
    static constexpr char TAG[] = "WifiDriver";

    static void wifi_event_handler(void *event_handler_arg, esp_event_base_t event_base, int32_t event_id,void *event_data);
    ErrorCode init();
    ErrorCode deinit();
    ErrorCode wifi_connection();

};

#endif // WIFI_HPP