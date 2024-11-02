#ifndef ERROR_CODE_HPP
#define ERROR_CODE_HPP

enum ErrorCode {
    E_OK = 0,
    E_NOT_OK,

    // TASKS
    E_TASK_CREATE_ERROR,
    E_TSK_STOP_ERROR,

    //GPIO
    LED_GPIO_STATE_ERROR
};

#endif // ERROR_CODE_HPP