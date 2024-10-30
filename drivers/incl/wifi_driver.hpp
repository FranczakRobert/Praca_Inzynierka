#ifndef WIFI_HPP
#define WIFI_HPP

#include <iostream>
#include "driver_abstract.hpp"

class WifiDriver : public Driver {

    public:
    WifiDriver();
    virtual ~WifiDriver();

    int start();


    private:
    int init();
    int deinit();
};

#endif // WIFI_HPP