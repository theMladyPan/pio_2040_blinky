from machine import Pin, deepsleep
import time

pin = Pin(23, Pin.OUT)   # set GPIO23 to output (external LED)
pin25 = Pin(25, Pin.OUT)  # set GPIO25 to output (onboard LED)
pin0 = Pin(0, Pin.IN)    # set GPIO0 to input (boot button)

pin.value(1)             # turn on diode for 10ms
time.sleep(0.01)
pin.value(0)             # turn off diode
deepsleep(10000)         # sleep for 10 seconds
