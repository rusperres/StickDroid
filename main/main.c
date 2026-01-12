#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#define LED_PIN 13

void app_main(void){
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_INPUT);
    while(1){
        int STATE = gpio_get_level(LED_PIN);
        printf("%d\n", STATE);
        vTaskDelay(1);
    }
}


    
