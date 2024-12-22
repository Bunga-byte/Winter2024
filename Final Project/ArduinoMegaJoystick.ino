int joystickX = A0;   // Joystick X-axis
int joystickY = A1;   // Joystick Y-axis

void setup() {
  Serial.begin(115200);  // Communication with ESP32
}

void loop() {
  int xVal = analogRead(joystickX);  // Read joystick X-axis
  int yVal = analogRead(joystickY);  // Read joystick Y-axis

  // Send data to ESP32
  Serial.print(xVal);
  Serial.print(",");
  Serial.println(yVal);

  delay(100); // Adjust delay as needed
}

