#include <Arduino.h>
#include <numeric>
#include <algorithm>
#include <map>
#include <sstream>
#include "esp_log.h"

#define PIN            22 // GPIO pin connected to the LED


void setup() {
    Serial.begin(115200);
    while (!Serial) {
        delay(10);
    }
    ESP_LOGI("main", "Hello world!");
    // define pin as output
    pinMode(PIN, OUTPUT);
    digitalWrite(PIN, LOW);
    delay(2000);
    
    digitalWrite(PIN, HIGH);
    delay(100);    // Wait for 10ms
    digitalWrite(PIN, LOW);
    delay(1900);
    esp_deep_sleep_start();
}

void loop() {
}
