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
Adafruit_DCMotor *motor_left = AFMS.getMotor(1);
Adafruit_DCMotor *motor_right = AFMS.getMotor(2);
int inpt;
int left_dir;
int left_speed_inpt;
int right_dir;
int right_speed_inpt;
int min_speed = 40;
int max_speed = 200;
int left_speed;
int right_speed;



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
  motor_left->setSpeed(150);
  motor_left->run(FORWARD);
  // turn on motor
  motor_left->run(RELEASE);
  motor_right->setSpeed(150);
  motor_right->run(FORWARD);
  // turn on motor
  motor_right->run(RELEASE);
}

void loop() {
  
  //Serial.println("1");
 
 if ( Serial.available())     //Checks the availability of Serial port 
 {
  
  //inpt = Serial.read();
  inpt = Serial.parseInt();
  Serial.print(inpt);
    
 }
  //1414
  left_dir    =inpt/1000;
  left_speed_inpt  =(inpt%1000)/100;
  right_dir   =(inpt%100)/10;
  right_speed_inpt =(inpt%10);
 /*
  Serial.print("left_dir");
  Serial.println(left_dir);
  Serial.print("left_speed_inpt");
  Serial.println(left_speed_inpt);
  Serial.print("right_dir");
  Serial.println(right_dir);
  Serial.print("right_speed_inpt");
  Serial.println(right_speed_inpt);
*/
  //Set Speeds:

  left_speed = min_speed + left_speed_inpt / 10. * (max_speed-min_speed);
  right_speed = min_speed + right_speed_inpt / 10. * (max_speed-min_speed);
  
  motor_left->setSpeed(left_speed);
  motor_right->setSpeed(right_speed);
  Serial.print("right_speed");
  Serial.println(right_speed);
  Serial.print("left_speed");
  Serial.println(right_speed);

  //Run Motors
  //Left Motor
  if (left_dir == 1){
    motor_left->run(FORWARD);
  } else if (left_dir == 2){
    motor_left->run(BACKWARD);
  } else if (left_dir == 0){
    motor_left->run(RELEASE);
  } else{
    Serial.print("Fehlerhafte Eingabe für left dir: ");
    Serial.println(left_dir);
  }
  //Right Motor
  if (right_dir == 1){
    motor_right->run(FORWARD);
  } else if (right_dir == 2){
    motor_right->run(BACKWARD);
  } else if (right_dir == 0){
    motor_right->run(RELEASE);
  } else{
    Serial.print("Fehlerhafte Eingabe für right dir: ");
    Serial.println(right_dir);
  }



  /*

  if (inpt == 1){          //Check if the received character is 1
    motor_left->run(FORWARD);
  }
  else if (inpt == 0){     ////Check if the received character is 0
    motor_left->run(RELEASE);
  }
  else if (inpt >2){
    motor_left->setSpeed(inpt);
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
  delay(1000);
}
