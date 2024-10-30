#ifndef WIFI_HPP
#define WIFI_HPP

#include <iostream>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_log.h"

#include <stdio.h> //for basic printf commands
#include <string.h> //for handling strings
#include "freertos/FreeRTOS.h" //for delay,mutexs,semphrs rtos operations
#include "esp_system.h" //esp_init funtions esp_err_t 
#include "esp_wifi.h" //esp_wifi_init functions and wifi operations
#include "esp_log.h" //for showing logs
#include "esp_event.h" //for wifi event
#include "nvs_flash.h" //non volatile storage
#include "lwip/err.h" //light weight ip packets error handling
#include "lwip/sys.h" //system applications for light weight ip apps

#include "driver_abstract.hpp"

class WifiDriver : public Driver {

    public:
    WifiDriver();
    ~WifiDriver();

    int start();


    private:
    static void wifi_event_handler(void *event_handler_arg, esp_event_base_t event_base, int32_t event_id,void *event_data);
    int init();
    int deinit();
    void wifi_connection();
    
};

#endif // WIFI_HPP