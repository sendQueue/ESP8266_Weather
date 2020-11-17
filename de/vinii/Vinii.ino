/**
   @author sendQueue <Vinii>

           Further info at Vinii.de or github@vinii.de, file created at
           16.11.2020. Use is only authorized if given credit!

*/
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>

#include <Wire.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

#define STASSID "WLAN_SSID"
#define STAPSK  "WLAN_PSK"

const char *ssid = STASSID;
const char *password = STAPSK;
const char* serverName = "http://vinii.xyz/esp/data/receiveData.php";
const String apiKey = "apiKey";

Adafruit_BME280 bme;

int lastMill = -60000;

void sendDataVini() {
  Serial.println("Sending..");

  double temp = bme.readTemperature() - 0.5;
  double hum = bme.readHumidity();
  double pres = (bme.readPressure() / 100.0F) + 2.5;

  HTTPClient http;
  http.begin(serverName);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  String httpRequestData = "apiKey=" + apiKey + "&t=" + temp + "&h=" + hum + "&p=" + pres + "";

  Serial.print("httpRequestData: ");
  Serial.println(httpRequestData);

  Serial.print("HTTP Response code: ");
  Serial.println(http.POST(httpRequestData));
  
  http.end();
  
  delay(5000);
}

void setup(void) {
  bme.begin(0x76);
  
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop(void) {
  if (millis() - lastMill > 55000) {
    sendDataVini();
    lastMill = millis();
  }
}

