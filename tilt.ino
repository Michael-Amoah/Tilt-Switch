/*
 *  Michael Amoah 
 *  ECE484 Chip Interface Project
 *  Tilt Switch Project Test
 *  tilt.ino
 */

int tiltPin=2;
int tiltVal;
const int SpeakerPin = 11;
int redLED=13;
 
void setup() {
  // put your setup code here, to run once:
pinMode(tiltPin,INPUT);
pinMode(redLED,OUTPUT);
digitalWrite(tiltPin,HIGH);
Serial.begin(9600);
}
 
void loop() {
  // put your main code here, to run repeatedly:
tiltVal=digitalRead(tiltPin);
Serial.println(tiltVal);
if (tiltVal==0){
  digitalWrite(redLED,HIGH);
  tone(SpeakerPin, 494, 500);
  delay(500);
}
else { // (tiltVal==1)
  digitalWrite(redLED,LOW);
  
}
}
