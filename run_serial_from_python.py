import serial
import time


arduinoData = serial.Serial('com4',9600)

def led_on():
    arduinoData.write(1)

def led_off():
    arduinoData.write(0)

time.sleep(0.5)
led_on()

print("done")