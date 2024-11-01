#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_log.h"
#include "esp_system.h"


class Driver {
    public:
    virtual ~Driver() {};
    virtual int start() = 0;

    private:
    virtual int init() = 0;
    virtual int deinit() = 0;
};

#endif // DRIVER