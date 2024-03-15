#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>

// Replace with your network credentials
const char *ssid = "POCO X2";
const char *password = "12345678";
#define enablePin  4
void setup() {
  Serial.begin(115200);
  // Uncomment the line below to enable detailed debug output
  // Serial.setDebugOutput(true);
  Serial.println();
  Serial.println();
  Serial.println("Connecting to WiFi...");

  pinMode(enablePin, OUTPUT);
  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Wait for WiFi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connected to WiFi");
}

void loop() {
  // Check if WiFi is connected
  if (WiFi.status() == WL_CONNECTED) {

    // Create a unique_ptr for WiFiClientSecureBearSSL
    std::unique_ptr<BearSSL::WiFiClientSecure> client(new BearSSL::WiFiClientSecure);

    // Ignore SSL certificate validation
    client->setInsecure();

    // Create an HTTPClient instance
    HTTPClient https;

    // Initializing an HTTPS communication using the secure client
    Serial.println("[HTTPS] begin...");

    if (https.begin(*client, "https://dogo-7.onrender.com/find-person")) {  // HTTPS
      // Set timeout to 10 seconds (adjust as needed)
      https.setTimeout(10000);
      
      Serial.println("[HTTPS] GET...");

      // Start connection and send HTTP header
      int httpCode = https.GET();

      // Check HTTP response code
      if (httpCode > 0) {
        // HTTP header has been sent, and Server response header has been handled
        Serial.printf("[HTTPS] GET... code: %d\n", httpCode);

        // File found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = https.getString();
          Serial.println(payload);
           if (payload == "{\"message\":\"found\"}") {
            // Enable D1 pin
            digitalWrite(enablePin, HIGH);
            Serial.println("D1 pin enabled!");
          } 
        }
      } else {
        Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
      }

      https.end();
    } else {
      Serial.println("[HTTPS] Unable to connect");
    }
  } else {
    Serial.println("WiFi not connected. Reconnecting...");
    // Reconnect to WiFi if not connected
    WiFi.reconnect();
  }

  Serial.println();
  Serial.println("Waiting 2min before the next round...");
  delay(2000);
}
