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


int inpt;
int left;
int ledpin = 13;   //Declaring the LED pin
int ledpin2 = 12;   //Declaring the LED pin



void setup() {
  Serial.begin(9600);           //Initializing the Serial Port to Baud rate 9600
  pinMode(ledpin, OUTPUT);      //Defining the Led pin as output 
  pinMode(ledpin2, OUTPUT);      //Defining the Led pin as output 
  // put your setup code here, to run once:

}

void loop() {
 if ( Serial.available())     //Checks the availability of Serial port 
 {
  inpt = Serial.parseInt();
  Serial.print(inpt);
 }
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

  delay(100);
}
