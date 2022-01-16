//Die Anleitung findest du unter: https://www.mymakerstuff.de/arduinotutorial-drei-leds-ansteuern/

int ledRot   = 13;                      // definiere Variable für Pin 13
int ledGelb  = 12;                      // definiere Variable für Pin 12
//int ledGruen = 11;                      // definiere Variable für Pin 11

void setup() {

  pinMode(ledRot, OUTPUT);              //
  pinMode(ledGelb, OUTPUT);             // definiere die LEDs als Ausgänge
//  pinMode(ledGruen, OUTPUT);            //
}

void loop() {

  digitalWrite(ledRot, LOW);            //
  digitalWrite(ledGelb, LOW);           // mache die LEDs aus
 // digitalWrite(ledGruen, LOW);          //

  digitalWrite(ledRot, HIGH);           // mache die rote LED an
  delay(1000);                          // und warte eine Sekunde

  digitalWrite(ledRot, LOW);            // mache die rote LED aus
  digitalWrite(ledGelb, HIGH);          // danach mache die gelbe LED an
  delay(1000);                          // und warte eine Sekunde

  digitalWrite(ledGelb, LOW);           // mache die gelbe LED aus
//  digitalWrite(ledGruen, HIGH);         // danach mache die grüne LED an
  delay(1000);                          // und warte eine Sekunde
} 
