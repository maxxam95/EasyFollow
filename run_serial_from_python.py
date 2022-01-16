from socket import timeout
import serial
import time


arduinoData = serial.Serial('COM4',9600) #,timeout = 1

def led_on():
    arduinoData.write(1)

def led_off():
    arduinoData.write(0)

time.sleep(1)
# t=0
# while(t<2000):
#     if (t%10==0):
#         print (t)
#         led_on()
#     t+=1
led_on()
time.sleep(2)
#inp=arduinoData.read()
#print(str(inp))
print("done")