/*
 *  Michael Amoah 
 *  ECE484 Chip Interface Project
 *  Tilt Switch
 *  tilt.ino - Test on Arduino IDE
 */

int tiltPin=7;
int tiltVal;
const int SpeakerPin = 11;
int redLED=5;
 
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
