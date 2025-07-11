# WiFiManager Library

This library provides a simple interface for connecting to WiFi networks with retry logic.

## Usage

```cpp
#include <WiFiManager.h>

void setup() {
    Serial.begin(115200);

    // Connect to WiFi with retry logic
    bool connected = ConnectToWiFi("your_ssid", "your_password", 10);

    if (connected) {
        Serial.println("Connected to WiFi successfully!");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("Failed to connect to WiFi");
    }
}
```

## API

### `bool ConnectToWiFi(const char* ssid, const char* password, int maxRetries = 0)`

Connect to a WiFi network with retry logic.

**Parameters:**
- `ssid`: WiFi network name (SSID)
- `password`: WiFi network password
- `maxRetries`: Maximum number of connection attempts (0 for unlimited retries)

**Returns:**
- `true` if connected successfully
- `false` if connection failed after maximum retries

**Example:**
```cpp
// Connect with unlimited retries
bool connected = ConnectToWiFi("MyWiFi", "MyPassword");

// Connect with maximum 5 retries
bool connected = ConnectToWiFi("MyWiFi", "MyPassword", 5);
```

The function will automatically handle connection retries with increasing delay between attempts.
