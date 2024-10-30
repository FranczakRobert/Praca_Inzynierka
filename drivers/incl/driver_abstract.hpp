#ifndef DRIVER_HPP
#define DRIVER_HPP
#include <iostream>

class Driver {
    public:
    Driver() {
        std::cout << "Abstract Constructor" << std::endl;
    }
    virtual ~Driver() {
        std::cout << "Abstract Destructor" << std::endl;
    }
    virtual int start() = 0;

    private:
    virtual int init() = 0;
    virtual int deinit() = 0;
};

#endif // DRIVER