#include <Arduino.h>
#include <const.h>
#include <secrets.h>
#include <WiFi.h>

bool ConnectToWiFi(const char* ssid, const char* password, int maxRetries = 0) {
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

// LED blink task function
void blinkLEDTask(void* parameter) {
  for (int i = 0; i < 3; i++) {
    delay(250);
    digitalWrite(LED_PIN, LOW);
    delay(250);
    digitalWrite(LED_PIN, HIGH);
  }
  vTaskDelete(NULL); // Delete this task when done
}


void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  digitalWrite(LED_PIN, HIGH);

  bool connected = false; //ConnectToWiFi(WIFI_SSID, WIFI_PASSWORD, 10);
  if (connected != true) {
    while (true) {
      Serial.println("ERROR: Cannot connect to wifi. Board won't work.");
      delay(60000);
    }
  }

  // Create a separate task for blinking the LED
  xTaskCreate(
    blinkLEDTask,       // Task function
    "Blink LED",        // Name of task
    1000,               // Stack size (in words)
    NULL,               // Task input parameter
    1,                  // Priority
    NULL                // Task handle
  );
}

void loop() {
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP().toString());
  delay(5000);
}

