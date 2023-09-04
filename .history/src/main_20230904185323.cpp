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
}

void loop() {
    digitalWrite(PIN, HIGH);
    delay(100);    // Wait for 10ms

    pixels.setPixelColor(0, pixels.Color(0, 0, 0)); // Off
    
    pixels.show();
    delay(1900);
}
