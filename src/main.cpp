#include <Arduino.h>

#define LED_PIN 21  // Typical onboard LED for XIAO ESP32S3 (check your board's schematic)

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  Serial.println("LED toggled");
  delay(500);
}
