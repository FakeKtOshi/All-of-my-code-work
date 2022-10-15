#include <Servo.h> 
Servo servo; 
int trig = 10;
int echo = 9;
void setup()
{
  servo.attach(4);
  servo.write(0);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}
void loop()
{
  long duration, inches, cm; 
  digitalWrite(trig, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trig, HIGH);
  delayMicroseconds(5); 
  digitalWrite(trig, LOW);            
  duration = pulseIn(echo, HIGH);
  inches = microsecondToInches(duration); 
  cm = microsecondsToCentimeters(duration);
  Serial.print(inches); 
  Serial.print("in, "); 
  Serial.print(cm); 
  Serial.print("cm"); 
  Serial.println(); 
 if (cm <= 60){
    servo.write(178);
    delay(5000);
}
 if (cm > 60){
    servo.write(90);}
    delay(10);
} 
 long microsecondToInches(long microseconds){ 
 // The speed of sound is 73.746 ms per inches  
 return microseconds / 74 / 2; 
} 
 long microsecondsToCentimeters(long microseconds){ 
 // The speed of sound is 340 m/s or 29 microseconds per centimeter. 
 // The ping travels out and back, so to find the distance of the 
 // object we take half of the distance travelled. 
 return microseconds / 29 / 2;   
}
