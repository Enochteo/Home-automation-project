#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "YOUR-WIFI-NAME";
const char* password = "YOUR-WIFI-PASSWORD";
const char* serverName = "YOUR-SERVER-IP_ADDRESS";

const int ledPin = 2;

void setup() {
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);

    dht.begin();
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");



    
}

void loop() {
    // nothing for now
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient postHttp;
        postHttp.begin(serverName);
        postHttp.addHeader("Content-Type", "application/json");


        float temperature = dht.readTemperature();
        float humidity = dht.readHumidity();
        float light = 23.0;
    
        if (isnan(temperature) || isnan(humidity)) {
            Serial.println("Sensor read failed!");
            return;
        }

        String payload = "{";
        payload += "\"temperature\": " + String(temperature, 2) + ",";
        payload += "\"humidity\": " + String(humidity, 2) + ",";
        payload += "\"lightData\": " + String(light, 2);
        payload += "}";
        
        Serial.print("Sending: ");
        Serial.print(payload);

        postHttp.POST(payload);
        postHttp.end();
        HTTPClient getHttp;
        getHttp.begin("http://10.51.79.155:5001/status");
        int code = getHttp.GET();

        if (code == 200) {
            String response = getHttp.getString();
            Serial.println("Status response: " + response);

            int index = response.indexOf("\"lightState\":");
            if (index != -1) {
                String value = response.substring(index + 13);  // skip past key
                value.trim();
                bool lightState = value.startsWith("true");
                digitalWrite(ledPin, lightState ? HIGH : LOW);
                Serial.println(lightState ? "LED ON" : "LED OFF");
            }
        } else {
            Serial.print("GET /status failed, code: ");
            Serial.println(code);
        }

        getHttp.end();
    }

    delay(3000);
    }

