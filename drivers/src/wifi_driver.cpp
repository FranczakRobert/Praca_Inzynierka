#include "wifi_driver.hpp"
#include "driver_abstract.hpp"

const char* TAG = "WifiDriver";


int retry_num=0;


WifiDriver::WifiDriver() {
    init();
}

WifiDriver::~WifiDriver() {
    deinit();
}

int WifiDriver::init() {

    return 0;
}

int WifiDriver::deinit() {
    ESP_LOGI(TAG, "Initialized successfully");
    return 0;
}

int WifiDriver::start() {
    nvs_flash_init(); // this is important in wifi case to store configurations , code will not work if this is not added
    wifi_connection();
    return 0;
}

void WifiDriver::wifi_connection() {
    esp_netif_init(); //network interdace initialization
    esp_event_loop_create_default(); //responsible for handling and dispatching events
    esp_netif_create_default_wifi_sta(); //sets up necessary data structs for wifi station interface

    wifi_init_config_t wifi_initiation = WIFI_INIT_CONFIG_DEFAULT();//sets up wifi wifi_init_config struct with default values
    esp_wifi_init(&wifi_initiation); //wifi initialised with dafault wifi_initiation

    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, wifi_event_handler, NULL);//creating event handler register for wifi
    esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, wifi_event_handler, NULL);//creating event handler register for ip event


    wifi_config_t wifi_configuration;
    strcpy((char*)wifi_configuration.sta.ssid, NAME);
    strcpy((char*)wifi_configuration.sta.password, PSSWD);   

    esp_wifi_set_config(WIFI_IF_STA, &wifi_configuration);  // ustawienie konfiguracji dla stacji (klienta)
    esp_wifi_start();//start connection with configurations provided in funtion
    esp_wifi_set_mode(WIFI_MODE_STA);//station mode selected
    esp_wifi_connect(); //connect with saved ssid and pass
    printf( "wifi_init_softap finished. SSID:%s  password:%s",wifi_configuration.sta.ssid,wifi_configuration.sta.password);
}

void WifiDriver::wifi_event_handler(void *event_handler_arg, esp_event_base_t event_base, int32_t event_id,void *event_data){

    switch (event_id){
        case WIFI_EVENT_STA_START:
            ESP_LOGI(TAG, "WIFI CONNECTING....");
            break;
    
        case WIFI_EVENT_STA_CONNECTED:
            ESP_LOGI(TAG, "WiFi CONNECTED");
            break;

        case WIFI_EVENT_STA_DISCONNECTED:
            ESP_LOGI(TAG, "WiFi lost connection");
            
            if(retry_num<5){
                esp_wifi_connect();
                retry_num++;
                ESP_LOGI(TAG, "Retrying to Connect...");
            }
            break;

        case IP_EVENT_STA_GOT_IP:
            ESP_LOGI(TAG, "Wifi got IP...");
        break;
        
        default:
        break;
    }
}
