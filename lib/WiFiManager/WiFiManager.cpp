#include "WiFiManager.h"

bool ConnectToWiFi(const char* ssid, const char* password, int maxRetries) {
  int retryCount = 0;
  int waitTime = 0;
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED && (maxRetries == 0 || retryCount < maxRetries)) {
    Serial.print("Attempting to connect to WiFi. SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED) {
      // Wait up to 20 seconds per attempt
      if (waitTime < 20000) {
        waitTime += 5000;
      }
      delay(waitTime);
    }
    retryCount++;
    if (WiFi.status() != WL_CONNECTED) {
      Serial.println("Connection failed, retrying...");
      delay(1000);
      WiFi.disconnect();
      WiFi.begin(ssid, password);
    }
  }
  return WiFi.status() == WL_CONNECTED;
}