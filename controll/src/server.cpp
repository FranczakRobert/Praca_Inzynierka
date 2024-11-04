#include "server.hpp"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

esp_err_t Server::get_handler(httpd_req_t *req)
{
    /* Send a simple response */
    const char resp[] = "<!DOCTYPE html>\
        <html>\
        <head>\
            <title>ESP32 Web Server</title>\
            <style>\
                body { font-family: Arial, sans-serif; background-color: #f0f0f0; }\
                h1 { color: #333; }\
                .container { max-width: 600px; margin: 0 auto; padding: 20px; background-color: white; border-radius: 8px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); }\
            </style>\
            <script>\
            let state = 0;\
                function showAlert() {\
                    state = state === 0 ? 1 : 0; // Przełączanie między 0 a 1\
                    console.log('Stan po kliknięciu:', state); // Log stanu\
                    alert(\'Hello from ESP32!\');\
                }\
            </script>\
        </head>\
        <body>\
            <div class=\"container\">\
                <h1>Welcome to ESP32 Web Server</h1>\
                <p>This is a simple web page served by the ESP32.</p>\
                <button onclick=\"showAlert()\">Click me!</button>\
            </div>\
        </body>\
        </html>";

    httpd_resp_send(req, resp, HTTPD_RESP_USE_STRLEN);
    printf("HALO HALO GET TEST!!!!\n");
    return ESP_OK;
}

esp_err_t Server::post_handler(httpd_req_t *req)
{
    char content[100];

    size_t recv_size = MIN(req->content_len, sizeof(content));

    int ret = httpd_req_recv(req, content, recv_size);
    if (ret <= 0) {  /* 0 return value indicates connection closed */
        /* Check if timeout occurred */
        if (ret == HTTPD_SOCK_ERR_TIMEOUT) {
            httpd_resp_send_408(req);
        }
        return ESP_FAIL;
    }

    const char resp[] = "Hello from ESP32!";
    httpd_resp_send(req, resp, HTTPD_RESP_USE_STRLEN);
    return ESP_OK;
}


void Server::stop_webserver(httpd_handle_t server)
{
    if (server) {
        httpd_stop(server);
    }
}

httpd_handle_t Server::start_webserver(void)
{
    /* Generate default configuration */
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    httpd_handle_t server = NULL;

    if (httpd_start(&server, &config) == ESP_OK) {
        /* Register URI handlers */
        httpd_register_uri_handler(server, &uri_get);
        httpd_register_uri_handler(server, &uri_post);
    }
    /* If server failed to start, handle will be NULL */
    return server;
}

Server::Server(Led& led) : wifi_led_for(led){

}

Server::~Server()
{

}
