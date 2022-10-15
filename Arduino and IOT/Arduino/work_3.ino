#include <Servo.h>
int vrPin=A3;
Servo servo;
Servo servo1;
void setup()
{
  servo.attach(2);
  servo.write(0);
  servo1.attach(3);
  servo1.write(0);
  pinMode(vrPin,INPUT);
  Serial.begin(9600);
}
void loop()
{
  int val=analogRead(vrPin);
  int val1=map(val,0,1023,0,180);
  servo.write(val1);
  delay(10);
  int val2=analogRead(vrPin);
  int val3=map(val2,0,1023,180,0);
  servo1.write(val3);
  delay(10);
}
