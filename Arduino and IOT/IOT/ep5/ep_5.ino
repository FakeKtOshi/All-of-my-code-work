
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLnOaDh7Kx---"
#define BLYNK_DEVICE_NAME "3LED---"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
int LED1=5;
int LED2=14; //GPIO5
int LED3=12; //GPIO6
void setup()
{
Serial.begin(115200);
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
delay(100);

 BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}
BLYNK_WRITE(V1){
int val1=param.asInt();
Serial.print("LED1=");
Serial.println(param.asInt());
if (param.asInt()){
digitalWrite(LED1, val1);
} else {
digitalWrite(LED1, val1);
}
}
BLYNK_WRITE(V2){
int val2=param.asInt();
Serial.print("LED2=");
Serial.println(param.asInt());
if (param.asInt()){
digitalWrite(LED2, val2);
} else {
digitalWrite(LED2, val2);
}
}
BLYNK_WRITE(V3){
int val3=param.asInt();
Serial.print("LED3=");
Serial.println(param.asInt());
if (param.asInt()){
digitalWrite(LED3, val3);
} else {
digitalWrite(LED3, val3);
}
}
