from machine import Pin, deepsleep
import time

pin23 = Pin(23, Pin.OUT)  # set GPIO23 to output (external LED)
pin25 = Pin(25, Pin.OUT)  # set GPIO25 to output (onboard LED)
pin24 = Pin(24)  # set GPIO24 to input (boot button)
pin24.init(Pin.IN, Pin.PULL_UP)  # enable pull-up resistor
if pin24.value() == 0:  # if boot button is pressed
    while pin24.value() == 0:
        pin25.value(1)  # turn on onboard LED
        time.sleep(0.1)  # sleep for 100ms
        
    while pin24.value() == 1: ...
pin25.value(0)  # turn off onboard LED

while 1:
    pin23.value(1)  # turn on diode for 10ms
    pin25.value(1)  # turn on onboard LED
    time.sleep(0.01)
    pin23.value(0)  # turn off diode
    pin25.value(0)  # turn off onboard LED
    time.sleep(1)  # sleep for 1 seconds
