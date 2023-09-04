from machine import Pin, deepsleep
import time


time.sleep(5)  # sleep 5 seconds to give you time to connect
pin = Pin(23, Pin.OUT)   # set GPIO0 to output to drive NeoPixels
pin.value(1)             # turn on diode for 10ms
time.sleep(0.01)
pin.value(0)             # turn off diode
deepsleep(10000)         # sleep for 10 seconds
