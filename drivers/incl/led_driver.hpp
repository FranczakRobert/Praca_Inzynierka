#include "driver_abstract.hpp"

class LED : public Driver {
    public:
    LED();
    ~LED();
    int start();

    private:
    int init();
    int deinit();
};