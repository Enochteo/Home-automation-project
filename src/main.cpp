#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "YOUR-WIFI-NAME";
const char* password = "YOUR-WIFI-PASSWORD";
const char* serverName = "YOUR-SERVER-IP-ADDRESS";

const int ledPin = 2;

void setup() {
    Serial.begin(115200);
    // define led pinmode
    pinMode(ledPin, OUTPUT);

    // Begin temp sensor
    dht.begin();

    // connect to wifi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");



    
}

void loop() {
    if (WiFi.status() == WL_CONNECTED) {
        // init http post for sensor data
        HTTPClient postHttp;
        postHttp.begin(serverName);
        postHttp.addHeader("Content-Type", "application/json");

        // read sensor values
        float temperature = dht.readTemperature();
        float humidity = dht.readHumidity();
        float light = 23.0;
        
        // sensor error
        if (isnan(temperature) || isnan(humidity)) {
            Serial.println("Sensor read failed!");
            return;
        }
        
        // sensor payload to be converted to json
        String payload = "{";
        payload += "\"temperature\": " + String(temperature, 2) + ",";
        payload += "\"humidity\": " + String(humidity, 2) + ",";
        payload += "\"lightData\": " + String(light, 2);
        payload += "}";
        
        Serial.print("Sending: ");
        Serial.print(payload);

        postHttp.POST(payload);
        postHttp.end();

        // init get request for device state
        HTTPClient getHttp;
        getHttp.begin(serverName);
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

