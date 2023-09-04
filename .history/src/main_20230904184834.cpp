#include <Arduino.h>

#define PIN            23 // GPIO pin connected to the NeoPixel data line

void setup() {
    Serial.begin(115200);
    esp_logi("main", "Hello World!");
    }

void loop() {
    pixels.setPixelColor(0, pixels.Color(255, 255, 0)); // Red
    pixels.show(); // Send the updated pixel colors to the hardware
    delay(100);    // Wait for 10ms

    pixels.setPixelColor(0, pixels.Color(0, 0, 0)); // Off
    
    pixels.show();
    delay(1900);
}
