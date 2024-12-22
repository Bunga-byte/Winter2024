#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "*********";
const char* password = "*********";

// IP address of ESP32 #2 (Server)
const char* serverIP = "********";  // Replace with actual IP of ESP32 #2
const uint16_t serverPort = ********;        // Port to communicate with ESP32 #2

WiFiClient client;

void setup() {
  Serial.begin(9600);  // Serial communication with Arduino Mega

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Connect to ESP32 #2 (Server)
  if (!client.connect(serverIP, serverPort)) {
    Serial.println("Connection to ESP32 #2 failed");
  } else {
    Serial.println("Connected to ESP32 #2");
  }
}

void loop() {
  if (Serial.available()) {
    // Read joystick data from Mega
    String data = Serial.readStringUntil('\n');
    
    // Send joystick data to ESP32 #2
    if (client.connected()) {
      client.println(data);
      Serial.println("Data sent to ESP32 #2: " + data);
    } else {
      Serial.println("Connection lost, retrying...");
      client.connect(serverIP, serverPort);  // Reconnect if connection is lost
    }
  }
}

