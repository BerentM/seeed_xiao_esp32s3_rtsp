#include <Arduino.h>
#include <WiFiManager.h>
#include <secrets.h>
#include <unity.h>

void test_connect_to_wifi_success() {
  bool result = ConnectToWiFi(WIFI_SSID, WIFI_PASSWORD, 1);
  TEST_ASSERT_TRUE(result);
}

void test_connect_to_wifi_fail() {
  bool result = ConnectToWiFi("InvalidSSID", "InvalidPassword", 1);
  TEST_ASSERT_FALSE(result);
}


void setup() {
  UNITY_BEGIN();

  RUN_TEST(test_connect_to_wifi_success);
  RUN_TEST(test_connect_to_wifi_fail);

  UNITY_END();
}

void loop() {
  // Empty loop for testing
}
