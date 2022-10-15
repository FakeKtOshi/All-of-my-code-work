#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Arduino_JSON.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels



const char* ssid = "zenzen";
const char* password = "0874141188";



// Your Domain name with URL path or IP address with path
String openWeatherMapApiKey = "8b4559c191f77d4f81596fc0d7e2c33d";
// Example:
//String openWeatherMapApiKey = "bd939aa3d23ff33d3c8f5dd1dd4";



// Replace with your country code and city
String city = "Tokyo";
String countryCode = "JP";



// THE DEFAULT TIMER IS SET TO 10 SECONDS FOR TESTING PURPOSES
// For a final application, check the API call limits per hour/minute to avoid getting blocked/banned
unsigned long lastTime = 0;
// Timer set to 10 minutes (600000)
//unsigned long timerDelay = 600000;
// Set timer to 10 seconds (10000)
unsigned long timerDelay = 10000;



String jsonBuffer;



#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



float temp,pressure,wind_speed;
int humidity,wind_degree;



void setup() {
Serial.begin(115200);



WiFi.begin(ssid, password);
Serial.println("Connecting");
while(WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.print("Connected to WiFi network with IP Address: ");
Serial.println(WiFi.localIP());

Serial.println("Timer set to 10 seconds (timerDelay variable), it will take 10 seconds before publishing the first reading.");



if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
Serial.println(F("SSD1306 allocation failed"));
for(;;);
}
Wire.setClock(400000L); // set I2C clock to 400kHz
delay(2000);
display.clearDisplay();



display.setTextSize(1);
display.setTextColor(WHITE);
display.setCursor(0, 0);
display.println(" Internet Weather");
display.print(" Station - Japan");
display.display();
}



void loop() {
// Send an HTTP GET request
if ((millis() - lastTime) > timerDelay) {
// Check WiFi connection status
if(WiFi.status()== WL_CONNECTED){
String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + countryCode + "&APPID=" + openWeatherMapApiKey;

jsonBuffer = httpGETRequest(serverPath.c_str());
Serial.println(jsonBuffer);
JSONVar myObject = JSON.parse(jsonBuffer);

// JSON.typeof(jsonVar) can be used to get the type of the var
if (JSON.typeof(myObject) == "undefined") {
Serial.println("Parsing input failed!");
return;
}



Serial.print("JSON object = ");
Serial.println(myObject);
Serial.print("Temperature: ");
Serial.println(myObject["main"]["temp"]);
Serial.print("Pressure: ");
Serial.println(myObject["main"]["pressure"]);
Serial.print("Humidity: ");
Serial.println(myObject["main"]["humidity"]);
Serial.print("Wind Speed: ");
Serial.println(myObject["wind"]["speed"]);
Serial.println("\n");



/* temp = myObject["main"]["temp"] - 273.15; // get temperature in °C
humidity = myObject["main"]["humidity"]; // get humidity in %
pressure = myObject["main"]["pressure"] /// 1000; // get pressure in bar
wind_speed = myObject["wind"]["speed"]; // get wind speed in m/s
wind_degree = myObject["wind"]["deg"]; // get wind degree in °
*/
display.setCursor(0, 24);
display.print("Temperature: "); //
display.print(myObject["main"]["temp"]);
display.print(" F");
display.print("Humidity : ");
display.print(myObject["main"]["humidity"]);
display.println("%");
display.print("Pressure :");
display.print(myObject["main"]["pressure"]);
display.println("bar");
display.print("Wind speed : ");
display.print(myObject["wind"]["speed"]);
display.println("m/s");
display.printf("Wind degree: ");
display.println(myObject["wind"]["deg"]);

display.drawRect(115, 24, 3, 3, WHITE); // put degree symbol ( ° )
display.drawRect(97, 56, 3, 3, WHITE);
display.display();
}
else {
Serial.println("WiFi Disconnected");
}
lastTime = millis();
}
}



String httpGETRequest(const char* serverName) {
WiFiClient client;
HTTPClient http;

// Your IP address with path or Domain name with URL path
http.begin(client, serverName);

// Send HTTP POST request
int httpResponseCode = http.GET();

String payload = "{}";

if (httpResponseCode>0) {
Serial.print("HTTP Response code: ");
Serial.println(httpResponseCode);
payload = http.getString();
}
else {
Serial.print("Error code: ");
Serial.println(httpResponseCode);
}
// Free resources
http.end();



return payload;
}
