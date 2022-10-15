#include<Servo.h>
int digitalPin = 8;
Servo myServo1;
Servo myServo2;
void setup() 
{
  pinMode(digitalPin, INPUT);
  myServo1.attach(9);
  myServo1.write(90);
  myServo2.attach(10);
  myServo2.write(90);
  Serial.begin(9600);
}
void loop() 
{
  int val = digitalRead(digitalPin);
  Serial.print("val = "); 
  Serial.println(val);  
  if (val == 0){
    myServo1.write(0);
    myServo2.write(0);
    delay(150);
    myServo1.write(90);
    myServo2.write(90);
    delay(10000);
  }
  if (val == 1){
    myServo1.write(90);
    myServo2.write(90);
    delay(150);
  }
}
