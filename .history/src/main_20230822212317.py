from machine import Pin
from neopixel import NeoPixel
import time

pin = Pin(23, Pin.OUT)   # set GPIO0 to output to drive NeoPixels
np = NeoPixel(pin, 1)   # create NeoPixel driver on GPIO0 for 1 pixels
r, g, b = np[0]         # get first pixel colour

while 1:
    np[0] = (255, 0, 0)  # set the first pixel to red
    np.write()  # write data to all pixels
    time.sleep(0.1)
    np[0] = (0, 0, 0)  # turn off
    time.sleep(1.9)
