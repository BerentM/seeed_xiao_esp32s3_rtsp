#include "WiFiManager.h"

bool ConnectToWiFi(const char* ssid, const char* password, int maxRetries) {
  int retryCount = 0;
  int waitTime = 0;
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED && (maxRetries == 0 || retryCount < maxRetries)) {
    Serial.print("Attempting to connect to WiFi. SSID: ");
    Serial.println(ssid);
    if (WiFi.status() != WL_CONNECTED) {
      // Wait up to 10 seconds per attempt
      if (waitTime < 10000) {
        waitTime += 2500;
      }
      delay(waitTime);
      retryCount++;
      if (WiFi.status() != WL_CONNECTED) {
        Serial.println("Connection failed, retrying...");
        Serial.print("Retry count: ");
        Serial.println(retryCount);
        WiFi.disconnect();
        WiFi.begin(ssid, password);
      }
    }
  }
  return WiFi.status() == WL_CONNECTED;
}
