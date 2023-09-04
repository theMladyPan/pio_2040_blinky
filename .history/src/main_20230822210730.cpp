#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include 

#define PIN            23 // GPIO pin connected to the NeoPixel data line
#define NUMPIXELS      1  // Number of NeoPixels in the strip

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    pixels.begin(); // Initialize the NeoPixel library
    pixels.show();  // Initialize all pixels to 'off'

    Serial.begin(115200);
    Serial.println("Boot OK!");
}

void loop() {
    // Turn on every other pixel with red color
    for (int i = 0; i < NUMPIXELS; i += 2) {
        pixels.setPixelColor(i, pixels.Color(255, 0, 0)); // Red
    }
    pixels.show(); // Send the updated pixel colors to the hardware
    delay(500);    // Wait for half a second

    // Turn off all pixels
    for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Off
    }
    pixels.show();
    delay(500);
}
