#ifndef SERVER_HPP
#define SERVER_HPP

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_log.h"
#include "esp_system.h"

#include "led_driver.hpp"

#include "esp_http_server.h"

class Server {
private:
    Led& wifi_led_for;

    httpd_uri_t uri_get = {
        .uri      = "/getTest",
        .method   = HTTP_GET,
        .handler  = &Server::get_handler,
        .user_ctx = &wifi_led_for
    };

    httpd_uri_t uri_post = {
        .uri      = "/postTest",
        .method   = HTTP_POST,
        .handler  = &Server::post_handler,
        .user_ctx = &wifi_led_for
    };

    static esp_err_t get_handler(httpd_req_t *req);
    static esp_err_t post_handler(httpd_req_t *req);


public:
    Server(Led& led);
    ~Server();

    httpd_handle_t start_webserver(void);
    void stop_webserver(httpd_handle_t server);

};

#endif // SERVER_HPP
