/*Serial Communication with Arduino 
 * Author: Electrofun 
 * For more information visit us: www.electrofun.co.in
 * Video explanation at: https://youtu.be/3Iha7kBGjHQ
 */


char data = '0';   //Variable to store the data
//String data;   //Variable to store the data
//char data = "qw";
int valA;
//char a = data - '0' ;
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
  valA = Serial.parseInt();
  //data = Serial.read();      // Read the data and stores it in variable
  //a = atoi(data);
  Serial.print(valA);
  //data = Serial.readString();
  Serial.print(data);       //Print the received data 
  //if (valA > 1 )
  //  Serial.print("test");       //Print the received data 
 }
 if (valA < 10)
  //if (data[0] == '1')
  if (valA == 1)          //Check if the received character is 1
  digitalWrite(ledpin, HIGH);   //Make the GPIO High 
  else if (valA == 0)     ////Check if the received character is 0
  //else if (data[0] == '0')     ////Check if the received character is 0
  digitalWrite(ledpin, LOW);    //Make the GPIO Low

//  ___
if (valA > 10)
  //if (data[1] == '1')
  
  if (valA == 11)          //Check if the received character is 1
  digitalWrite(ledpin2, HIGH);   //Make the GPIO High 
  else if (valA == 12)     ////Check if the received character is 0
  //else if (data[1] == '0')     ////Check if the received character is 0
  digitalWrite(ledpin2, LOW);    //Make the GPIO 

  delay(50);
}
