#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_log.h"
#include "esp_system.h"

#include "error_code.hpp"

class Driver {
    public:
    virtual ~Driver() {};
    virtual ErrorCode start() = 0;

    private:
    virtual ErrorCode init() = 0;
    virtual ErrorCode deinit() = 0;
};

#endif // DRIVER