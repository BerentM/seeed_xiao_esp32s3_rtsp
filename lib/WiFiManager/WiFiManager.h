#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Arduino.h>
#include <WiFi.h>

/**
 * @brief Connect to WiFi network with retry logic
 * 
 * @param ssid WiFi network name
 * @param password WiFi network password
 * @param maxRetries Maximum number of connection attempts (0 for unlimited)
 * @return true if connected successfully, false otherwise
 */
bool ConnectToWiFi(const char* ssid, const char* password, int maxRetries = 0);

#endif // WIFI_MANAGER_H