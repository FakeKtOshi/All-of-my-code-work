#include<Servo.h>
Servo myServo1;
Servo myServo2;
int joy_x=A0;
int joy_y=A1;
void setup() {
  Serial.begin(9600);
  pinMode(joy_x,INPUT);
  pinMode(joy_y,INPUT);
  myServo1.attach(5);
  myServo1.write(0);
  myServo2.attach(4);
  myServo2.write(0);
}
void loop() {
  int servoVal1=analogRead(joy_x);
  int servo1=map(servoVal1,0,1023,10,90);
  myServo1.write(servo1);
  int servoVal2=analogRead(joy_y);
  int servo2=map(servoVal2,0,1023,0,90);
  myServo2.write(servo2);
  Serial.print(servo1);
  Serial.print(" , ");
  Serial.println(servo2);
}
