#include <stdio.h>
#include "driver/gpio.h"
#include "driver/adc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#define SW_PIN 34
#define VRX_PIN 36
#define VRY_PIN 39


void app_main(void){
    adc1_config_width(ADC_WIDTH_BIT_12); // 12-bit ADC (0-4095)
    adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_11); // VRX_PIN = VP/GPIO36
    adc1_config_channel_atten(ADC1_CHANNEL_3, ADC_ATTEN_DB_11); // VRY_PIN = VN/GPIO39

    
    gpio_reset_pin(SW_PIN);
    gpio_set_direction(SW_PIN, GPIO_MODE_INPUT);
    gpio_pullup_en(SW_PIN);
    
    while(1){
        int sw = gpio_get_level(SW_PIN);
        int x = adc1_get_raw(ADC1_CHANNEL_0); // VRX
        int y = adc1_get_raw(ADC1_CHANNEL_3); // VRY

        printf("X=%d, Y=%d, SW=%d\n", x, y, sw);
        vTaskDelay(1);
    }
}


    
