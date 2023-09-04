#include <Arduino.h>
#include <NeoPixelBus.h>

#define PIN            24 // GPIO pin connected to the NeoPixel data line
#define NUMPIXELS      8  // Number of NeoPixels in the strip

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(NUMPIXELS, PIN);

void setup() {
  strip.Begin();
  strip.ClearTo(RgbColor(0)); // Turn off all pixels initially
  strip.Show();
}

void loop() {
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.SetPixelColor(i, RgbColor(255, 0, 0)); // Red
  }
  strip.Show();
  delay(500);

  strip.ClearTo(RgbColor(0)); // Turn off all pixels
  strip.Show();
  delay(500);
}