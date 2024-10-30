#ifndef DRIVER_HPP
#define DRIVER_HPP

class Driver {
    public:
    virtual ~Driver() {};
    virtual int start() = 0;

    private:
    virtual int init() = 0;
    virtual int deinit() = 0;
};

#endif // DRIVER