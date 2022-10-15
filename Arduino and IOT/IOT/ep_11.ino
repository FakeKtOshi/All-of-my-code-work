#include<ESP8266WiFi.h>
// Set GPIOs for LED and irsensor
int irPin = 5; //
int led = 16; //optional
// Detects whenever the door changed state
bool changeState = false;
// Holds reedswitch state (1=opened, 0=close)
bool state;
String detectState; //doorState
// Auxiliary variables (it will only detect changes that are 1500 milliseconds apart)
unsigned long previousMillis = 0;
const long interval = 1500;
const char* ssid = "zenzen";
const char* password = "0874141188";
const char* host = "maker.ifttt.com";
const char* apiKey = "dIBd--Pkx4pkbjGPz1I6Am";
// Runs whenever the reedswitch changes state
ICACHE_RAM_ATTR void irStatus() { //changeDoorStatus()
 Serial.println("State changed");
 changeState = true;
}
void setup() {
 // Serial port for debugging purposes
 Serial.begin(115200);
 // Read the current door state
 pinMode(irPin, INPUT);
 state = digitalRead(irPin);
 // Set LED state to match door state
 pinMode(led, OUTPUT);
 digitalWrite(led, state);
 
 // Set the reedswitch pin as interrupt, assign interrupt function and set CHANGE mode
 attachInterrupt(digitalPinToInterrupt(irPin), irStatus,
CHANGE);
 // Connect to Wi-Fi
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
 delay(500);
 Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected"); 
}
void loop() {
 if (changeState){
 unsigned long currentMillis = millis();
 if(currentMillis - previousMillis >= interval) {
 previousMillis = currentMillis;
 // If a state has occured, invert the current door state 
 state = !state;
 if(state) {
 detectState = "Not Detect";
 }
 else{
 detectState = "Detect";
 }
 digitalWrite(led, state);
 changeState = false;
 Serial.println(state);
 Serial.println(detectState);
 
 //Send email
 Serial.print("connecting to ");
 Serial.println(host);
 WiFiClient client;
 const int httpPort = 80;
 if (!client.connect(host, httpPort)) {
 Serial.println("connection failed");
 return;
 }
 
 String url = "/trigger/ir_detect/with/key/";
 url += apiKey;
 
 Serial.print("Requesting URL: ");
 Serial.println(url);
 client.print(String("POST ") + url + " HTTP/1.1\r\n" +
 "Host: " + host + "\r\n" +
 "Content-Type: application/x-www-formurlencoded\r\n" +
 "Content-Length: 13\r\n\r\n" +
 "value1=" + detectState + "\r\n");
 } 
 }
}
