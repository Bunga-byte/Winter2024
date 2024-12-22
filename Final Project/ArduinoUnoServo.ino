#include <Servo.h>

// Servo objects
Servo servoX;
Servo servoY;

// Pin assignments for servos
int servoPinX = 9;
int servoPinY = 10;

void setup() {
  // Attach servos
  servoX.attach(servoPinX);
  servoY.attach(servoPinY);

  // Start Serial communication with ESP32
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    // Read the joystick data from the ESP32 (e.g., "512,768")
    String data = Serial.readStringUntil('\n');
    
    // Parse the received data
    int separatorIndex = data.indexOf(',');
    String xValStr = data.substring(0, separatorIndex);
    String yValStr = data.substring(separatorIndex + 1);

    int xVal = xValStr.toInt();
    int yVal = yValStr.toInt();

    // Map the joystick values to the servo angles (0 to 180 degrees)
    int servoXAngle = map(xVal, 0, 1023, 0, 180);
    int servoYAngle = map(yVal, 0, 1023, 0, 180);

    // Move the servos
    servoX.write(servoXAngle);
    servoY.write(servoYAngle);

    // Debug print
    Serial.println("Servo X: " + String(servoXAngle) + " | Servo Y: " + String(servoYAngle));
  }
}
