/*Serial Communication with Arduino 
 * Author: Electrofun 
 * For more information visit us: www.electrofun.co.in
 * Video explanation at: https://youtu.be/3Iha7kBGjHQ
 */

/*
 * Übergabe Parameter:
 * Rechts: 
 * 1 = aus
 * 2 = an
 * 2 bis 9 geschwindigkeien
 * Links:
 * 10 = aus
 * 20 = an
 * 20 bis 90 geschwindigkeien
 */
#include <Adafruit_MotorShield.h>
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
//int inpt;
char inpt;
//int left;
//int ledpin2 = 13;   //Declaring the LED pin
//int ledpin = 12;   //Declaring the LED pin



void setup() {
  Serial.begin(9600);           //Initializing the Serial Port to Baud rate 9600
  //Serial.println("0");
  //pinMode(ledpin, OUTPUT);      //Defining the Led pin as output 
  //pinMode(ledpin2, OUTPUT);      //Defining the Led pin as output 
  // put your setup code here, to run once:

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");

  // Set the speed to start, from 0 (off) to 255 (max speed)
  myMotor->setSpeed(150);
  myMotor->run(FORWARD);
  // turn on motor
  myMotor->run(RELEASE);
}

void loop() {
  
  //Serial.println("1");
 
 if ( Serial.available())     //Checks the availability of Serial port 
 {
  
  inpt = Serial.read();
  //inpt = Serial.parseInt();
  Serial.print(inpt);
    
 }

  if (inpt == '1'){          //Check if the received character is 1
    //digitalWrite(ledpin, HIGH);   //Make the GPIO High 
    //Serial.print("test");
    //Serial.print(inpt);
    myMotor->run(FORWARD);
  }
  else if (inpt == '0'){     ////Check if the received character is 0
    //digitalWrite(ledpin, LOW);    //Make the GPIO Low
    //Serial.print(inpt);
    myMotor->run(RELEASE);
  }
 /*
 if (inpt < 10)
  if (inpt == 2)          //Check if the received character is 1
  digitalWrite(ledpin, HIGH);   //Make the GPIO High 
  else if (inpt == 1)     ////Check if the received character is 0
  digitalWrite(ledpin, LOW);    //Make the GPIO Low

if (inpt >= 10)
  left = inpt/10;
  if (left == 2)          //Check if the received character is 1
  digitalWrite(ledpin2, HIGH);   //Make the GPIO High 
  else if (left == 1)     ////Check if the received character is 0
  digitalWrite(ledpin2, LOW);    //Make the GPIO 
*/
  delay(100);
}
