int i = 0;
int led[8]={6,7,8,9,10,11,12,13};
void setup()
{
  Serial.begin(9600);
  for(int i=0;i<8;i++)
  {
    pinMode(led[i],OUTPUT);
  }
}
void loop()
{
  int vr=analogRead(A0);
  int vrl=map(vr,0,1023,3000,0);
  for(i=0;i<8;i++)
  {
    digitalWrite(led[i],1);
    delay(vrl);
  }
  for(i=7;i>=0;i--)
  {
    digitalWrite(led[i],0);
    delay(vrl);
  }
}
