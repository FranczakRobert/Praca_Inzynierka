#ifndef WIFI_HPP
#define WIFI_HPP

#include "driver_abstract.hpp"
#include <iostream>

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