#include "wifi_driver.hpp"

#define EXAMPLE_ESP_MAXIMUM_RETRY  5

static const char* TAG = "WifiDriver";
int retry_num=0;
Led *wifi_led = nullptr;


WifiDriver::WifiDriver(Led *led)
{
    wifi_led = led;
    init();
}

WifiDriver::~WifiDriver()
{
    deinit();
    ESP_ERROR_CHECK(nvs_flash_erase());
}

int WifiDriver::init() {
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    ESP_ERROR_CHECK(esp_netif_init()); //network interdace initialization
    ESP_ERROR_CHECK(esp_event_loop_create_default()); //responsible for handling and dispatching events
    esp_netif_create_default_wifi_sta(); //sets up necessary data structs for wifi station interface

    wifi_init_config_t wifi_initiation = WIFI_INIT_CONFIG_DEFAULT();//sets up wifi wifi_init_config struct with default values
    esp_wifi_init(&wifi_initiation); //wifi initialised with dafault wifi_initiation

    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT,
                                               ESP_EVENT_ANY_ID,
                                               &WifiDriver::wifi_event_handler,
                                               NULL));

    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT,
                                               IP_EVENT_STA_GOT_IP,
                                               &WifiDriver::wifi_event_handler,
                                               NULL));
    return 0;
}

int WifiDriver::deinit() {
    ESP_LOGI(TAG, "Deinicialized successfully");
    ESP_ERROR_CHECK(esp_wifi_deinit());
    return 0;
}

int WifiDriver::start() {
    wifi_connection();
    return 0;
}

void WifiDriver::wifi_connection() {
    wifi_config_t wifi_configuration;
    memset(&wifi_configuration, 0, sizeof(wifi_config_t));
    strcpy((char*)wifi_configuration.sta.ssid, NAME);
    strcpy((char*)wifi_configuration.sta.password, PSSWD);
    wifi_configuration.sta.threshold.authmode = WIFI_AUTH_WPA2_PSK;

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_configuration));
    vTaskDelay(2000 / portTICK_PERIOD_MS); 
    ESP_ERROR_CHECK(esp_wifi_start());
    vTaskDelay(2000 / portTICK_PERIOD_MS); 
    ESP_ERROR_CHECK(esp_wifi_connect());
    
}

void WifiDriver::wifi_event_handler(void *event_handler_arg, esp_event_base_t event_base, int32_t event_id,void *event_data){

    switch (event_id){
        case WIFI_EVENT_STA_START:
            ESP_LOGI(TAG, "WIFI CONNECTING....");
            break;
    
        case WIFI_EVENT_STA_CONNECTED:
            ESP_LOGI(TAG, "WiFi CONNECTED");
            if(nullptr != wifi_led) {
                wifi_led->turn_led_wifi_on();
            }
            else {
                ESP_LOGV(TAG,"LED IS NULL")
            }
            break;

        case WIFI_EVENT_STA_DISCONNECTED:
            ESP_LOGI(TAG, "WiFi lost connection");
            if(nullptr != wifi_led) {
                wifi_led->turn_led_wifi_off();
            }
            else {
                ESP_LOGV(TAG,"LED IS NULL")
            }
            if(retry_num< EXAMPLE_ESP_MAXIMUM_RETRY){
                esp_wifi_connect();
                retry_num++;
                ESP_LOGI(TAG, "Retrying to Connect...");
            }
            break;

        case IP_EVENT_STA_GOT_IP: {
                ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
                char ip_str[IP4ADDR_STRLEN_MAX];
                esp_ip4addr_ntoa(&event->ip_info.ip, ip_str, IP4ADDR_STRLEN_MAX);
                ESP_LOGI(TAG, "Got IP: %s", ip_str);
            }
            break;
        
        default:
            break;
    }
}
