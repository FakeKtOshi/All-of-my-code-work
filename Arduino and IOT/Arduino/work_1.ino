int led=8;
int Pin=A0;
void setup() 
{ 
 pinMode(led,OUTPUT);
 pinMode(Pin,INPUT);
 Serial.begin(9600);
}
void loop() 
{
  int vr=analogRead(Pin);
  int vrl=map(vr,0,1023,0,255);
  analogWrite(led, vrl);
  delay(100);
}
