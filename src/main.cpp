#include <Arduino.h>
#include <const.h>
#include <secrets.h>
#include <WiFi.h>
#include <WiFiManager.h>

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

  bool connected = ConnectToWiFi(WIFI_SSID, WIFI_PASSWORD, 10);
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

