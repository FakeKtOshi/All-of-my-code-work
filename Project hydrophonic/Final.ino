#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2 
#define relayFan 0
#define relayWater 16
#define relayLED 14
#define DHTTYPE    DHT11

LiquidCrystal_I2C lcd(0x27,20,4);

DHT dht(DHTPIN, DHTTYPE);

void setup(){
  //LCD
  lcd.init();                     
  lcd.backlight();
  
  Serial.begin(115200);
  
  //DHT-11
  dht.begin();
    
  pinMode(relayFan , OUTPUT);
  pinMode(relayWater , OUTPUT);
  pinMode(relayLED , OUTPUT);
}

void loop(){
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  
  //Serial.println("Humidity: ");
  //Serial.println(t);
  //Serial.println(h);
  
  //พัดลม
  if (h > 50){
    digitalWrite(relayFan,1);
  }
  else {
    digitalWrite(relayFan,0);
  }
  
  //รดน้ำ
  if (... == 1){
    digitalWrite(relayWater,1);
  }
  else{
    digitalWrite(relayWater,0);
  }
  
  //LED 
  if (... == 1){
     digitalWrite(relayWater,1);
  }
  else{
     digitalWrite(relayWater,0);
  }

  //LCD
  lcd.backlight();
   lcd.setCursor(0,0);
  lcd.print("Humidity : ");
  lcd.print(h);
   lcd.setCursor(0,1);
  lcd.print("Temperature : ");
  lcd.print(t);
   lcd.setCursor(0,2);
}
