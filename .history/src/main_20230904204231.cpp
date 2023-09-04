#include <Arduino.h>
#include <numeric>
#include <algorithm>
#include <map>
#include <sstream>
#include "esp_log.h"

#define LED_INT 22 // GPIO LED_INT connected to the LED
#define LED_EXT 19 // GPIO LED_EXT connected to the LED



void setup() {
    Serial.begin(115200);
    while (!Serial) {
        delay(10);
    }
    ESP_LOGI("main", "Hello world!");
    // define LED_INT as output
    // PinMode(LED_INT, OUTPUT);
    // define LED_EXT as output
    pinMode(LED_EXT, OUTPUT);
    digitalWrite(LED_EXT, LOW);

    digitalWrite(LED_INT, HIGH);
    delay(100);    // Wait for 10ms
    digitalWrite(LED_INT, LOW);
    esp_deep_sleep_start();
}

void loop() {
}
