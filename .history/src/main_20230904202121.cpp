#include <Arduino.h>
#include <numeric>
#include <algorithm>
#include <map>
#include <sstream>

#define PIN            22 // GPIO pin connected to the LED


void setup() {
    Serial.begin(115200);
    // define pin as output
    pinMode(PIN, OUTPUT);
    delay(1);
}

void loop() {
    digitalWrite(PIN, HIGH);
    delay(100);    // Wait for 10ms
    digitalWrite(PIN, LOW);
    delay(1900);
    esp_deep_sleep_start();
}
