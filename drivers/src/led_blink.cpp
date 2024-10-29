#include "led_blink.hpp"


Blinker::Blinker() {
    std::cout << "Blinker initialized." << std::endl;
}

void Blinker::blink_demo() {
    configure_led();

    for(int i = 0; i < 5; i++) {
        led_ON();
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        led_OFF();
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
    std::cout << "End of DEMO..." << std::endl;
}

void Blinker::led_ON() {
    gpio_set_level(BLINK_GPIO, 1);
}

void Blinker::led_OFF() {
    gpio_set_level(BLINK_GPIO, 0);
}

void Blinker::configure_led(void)
{
    ESP_LOGI("BLINKER", "Example configured to blink GPIO LED!");
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
}