#include <Arduino.h>
#include <numeric>
#include <algorithm>
#include <map>
#include <sstream>

#define PIN            23 // GPIO pin connected to the NeoPixel data line


void setup() {
    Serial.begin(115200);
    // define pin as output
    pinMode(PIN, OUTPUT);
    delay(5000);
}

void loop() {
    digitalWrite(PIN, HIGH);
    delay(100);    // Wait for 10ms
    digitalWrite(PIN, LOW);
    delay(1900);
    // enter rp2040 deep sleep for 5 seconds
    Serial.println("Entering deep sleep for 5 seconds");
    Serial.flush();
}
