#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int vrPin=A0;
void setup()
{
  lcd.begin();
  lcd.backlight();
  pinMode(vrPin,INPUT);
}
void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("Krit");
  int val=analogRead(vrPin);
  int val1=map(val,0,1023,0,1023);
  lcd.setCursor(0, 1);
  lcd.print(val1);
  lcd.noBlink();
  delay(150);
  lcd.clear();
}
