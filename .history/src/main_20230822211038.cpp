#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <pico/stdlib.h>


#define PIN            23 // GPIO pin connected to the NeoPixel data line
#define NUMPIXELS      1  // Number of NeoPixels in the strip

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    // Initialize the Pico SDK
    stdio_init_all();

    pixels.begin(); // Initialize the NeoPixel library
    pixels.show();  // Initialize all pixels to 'off'

    Serial.begin(115200);
    Serial.println("Boot OK!");
    }

void loop() {
    pixels.setPixelColor(0, pixels.Color(255, 0, 0)); // Red
    pixels.show(); // Send the updated pixel colors to the hardware
    delay(10);    // Wait for 10ms

    pixels.setPixelColor(0, pixels.Color(0, 0, 0)); // Off
    
    pixels.show();
    delay(990);
      // Configure the sleep mode
    sleep_config sleep_cfg;
    sleep_cfg = sleep_config::sleep_mode(SLEEP_MODE_DEEP);
    
    // Enter deep sleep mode
    sleep_enter(sleep_cfg);
}
