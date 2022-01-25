import serial
import time

arduino = serial.Serial(port='COM4', baudrate=115200, timeout=.1)
time.sleep(3) # 

def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data

lst=[2525]
#while True:
for num in lst:
    #num = input("Enter a number: ")

    value = write_read(str(num))
    time.sleep(0.1)
    print(value)
    print("Type: " + str(type(value)))
    
    