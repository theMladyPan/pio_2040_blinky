#include <Arduino.h>

#define PIN            23 // GPIO pin connected to the NeoPixel data line

// define variable bootCount in ESP32s RTC memory
RTC_DATA_ATTR int bootCount = 0;

void setup() {
    Serial.begin(115200);
    esp_logi("main", "Boot # !");
    }

void loop() {
    pixels.setPixelColor(0, pixels.Color(255, 255, 0)); // Red
    pixels.show(); // Send the updated pixel colors to the hardware
    delay(100);    // Wait for 10ms

    pixels.setPixelColor(0, pixels.Color(0, 0, 0)); // Off
    
    pixels.show();
    delay(1900);
}
