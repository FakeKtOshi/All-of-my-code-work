int vrPin=A0; //ESP8266 Analog pin ADC0 = A0
int led=5; //D1
int Val = 0; // value read from the pot
void setup() {
   Serial.begin(115200);
   pinMode(vrPin,INPUT);
   pinMode(led,OUTPUT);
}
void loop(){
   //read the analog in value
Val = analogRead(vrPin);
int val1=map(Val,12,1024,0,255);
//print the reading in the Serial Monitor
Serial.print("sensor  =   ");
Serial.print(Val);
Serial.print("    vr =   ");
Serial.print(val1);
analogWrite(led,val1);
delay(100);
}
