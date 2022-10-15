#include "AdafruitIO_WiFi.h"
#include <OneWire.h>
#include <DallasTemperature.h>

// ตั้งค่า key ของ Adafruit IO
#define IO_USERNAME  "KtOshi"
#define IO_KEY       "aio_nDOQ42QQeDvHf3LVfurSrb7Mluki"

// ตั้งค่าชื่อ wifi
#define WIFI_SSID "zenzen"
#define WIFI_PASS "0874141188"

#define SW D6

const int oneWireBus = 4;
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS); 
AdafruitIO_Feed *digital = io.feed("Tem button");
AdafruitIO_Feed *analog = io.feed("Tem text");
bool current = false;
void setup() {
  

  

  pinMode(SW, INPUT_PULLUP);
  sensors.begin();
  Serial.begin(115200);
  while (! Serial);
  Serial.print("Connecting to Adafruit IO");
  io.connect(); // เริ่มเชื่อมต่อ Adafruit IO


  while (io.status() < AIO_CONNECTED) { 
    Serial.print(".");
    delay(500);
  }
  digital->save(current);
  Serial.println();
  Serial.println(io.statusText()); 
  

}

void loop() {
  sensors.requestTemperatures();
 float temperatureC = sensors.getTempCByIndex(0);
 float temperatureF = sensors.getTempFByIndex(0);
 
 
  io.run(); // เริ่มทำงานร่วมกับ Adafruit IO
  if (digitalRead(SW) == 0) { 
    Serial.print(temperatureC);
  Serial.println("ºC");
  Serial.print(temperatureF);
  Serial.println("ºF");
    current = !current;
    digital->save(current); 
    analog->save(temperatureC);
    delay(500);
  }
}
