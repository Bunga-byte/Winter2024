#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "*******";
const char* password = "******";

// Set up the server on port ******
WiFiServer server(*****);

void setup() {
  Serial.begin(115200);  // Serial communication with Arduino Uno
  Serial1.begin(9600);  // Serial1 communication with Arduino Uno

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Print the IP address of ESP32 #2
  Serial.println("ESP32 #2 IP Address: ");
  Serial.println(WiFi.localIP());

  // Start the server
  server.begin();
  Serial.println("Server started");
}


void loop() {
  // Check if a client is connected
  WiFiClient client = server.available();
  
  if (client) {
    Serial.println("Client connected");

    while (client.connected()) {
      if (client.available()) {
        String data = client.readStringUntil('\n');  // Read the joystick data sent from ESP32 #1
        Serial.println("Data received: " + data);

        // Send the joystick data to Arduino Uno via Serial
        Serial1.println(data);  // Forward the data to the Uno
      }
    }
    client.stop();  // Stop the client when done
    Serial.println("Client disconnected");
  }
}
