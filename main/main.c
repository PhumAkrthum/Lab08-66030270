#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "sensor.h"

static const char *TAG = "SENSOR_TEST";

void app_main(void)
{
    ESP_LOGI(TAG, "🚀 Sensor Component Test Demo");
    
    // Initialize sensor module
    sensor_init();
    
    int counter = 0;
    
    while (1) {
        ESP_LOGI(TAG, "=== Loop %d ===", counter++);
        
        // Read sensor data
        sensor_read_data();
        
        // Get sensor values
        float temp = get_temperature();
        float humid = get_humidity();
        
        // Log sensor data to console
        ESP_LOGI(TAG, "Current Temperature: %.2fC", temp);
        ESP_LOGI(TAG, "Current Humidity: %.2f%%", humid);
        
        // Check sensor status every 3 loops
        if (counter % 3 == 0) {
            sensor_check_status();
        }
        
        vTaskDelay(pdMS_TO_TICKS(2000)); // 2 seconds delay
    }
}