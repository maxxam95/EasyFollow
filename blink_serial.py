import serial
import time
ser = serial.Serial(port='COM4', baudrate=115200, timeout=.1)
ser.flushInput()
time.sleep(5) # 
i = 1
while 1:
    
    #var=raw_input("Enter 0 or 1");
    #inpt = input("Enter a number: ")
    inpt =str(2929)
    print('TypeMAx:', type(inpt))
    #print(ser.write(input))
    ser.write(bytes(inpt, 'utf-8'))
    print(bytes(inpt, 'utf-8'))
    time.sleep(0.05)
    #print(ser.read())
    i+=1
    ser_bytes = ser.readline()
    decoded_bytes = (ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
    print(ser_bytes)

 #   if i==100:
    if i==3:    
        break
           