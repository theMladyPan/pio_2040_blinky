#include <Arduino.h>
#include <numeric>
#include <algorithm>
#include <map>
#include <sstream>
#include "esp_log.h"

#define LED_INT 22 // GPIO LED_INT connected to the LED
#define LED_EXT 19 // GPIO LED_EXT connected to the LED

/**
 * @brief Enter deep sleep for a given time
 * 
 * @param sleep_for_us - time to sleep in us
 * @param modem_off - true if modem should be turned off as well
 */
void enterDeepSleep(uint64_t sleep_for_us = TIME_TO_SLEEP * 1e6, bool modem_off = true)
{
    if(modem_off)
    {
        sim_modem.sleepEnable(false);
        sim_modem.poweroff();

        // disable battery
        // pinMode(BAT_EN, INPUT_PULLUP);ň
        gpio_set_level((gpio_num_t)BAT_EN, 0);
        V5V.turnOff();
        RSModem.turnOff();
        Network.turnOff();
    }
    auto cycleDuration = currentCycleTimeUs();
    ESP_LOGI(TAG, "Cycle duration: %.1fs, sleeping for: %.1fs", (float)(cycleDuration / 1e6), (float)((sleep_for_us-cycleDuration) / 1e6));
    Serial.flush();
    // setup wake up timer to wake up after rest of the cycle duration
    esp_sleep_enable_timer_wakeup(sleep_for_us - cycleDuration);
    // enter deep sleep 
    esp_deep_sleep_start();
}


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

    digitalWrite(LED_EXT, HIGH);
    delay(10);    // Wait for 10ms
    digitalWrite(LED_EXT, LOW);
    // setup timer to wake up every 10 seconds
    esp_deep_sleep_start();
}

void loop() {
}
