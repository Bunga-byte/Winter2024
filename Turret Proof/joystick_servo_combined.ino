#include <Servo.h>

Servo servoX;   // Servo controlled by X-axis
Servo servoY;   // Servo controlled by Y-axis

// Pin assignments
int joystickX = A0;   // Joystick X-axis connected to analog pin A0
int joystickY = A1;   // Joystick Y-axis connected to analog pin A1

int servoPinX = 9;    // Servo X connected to digital pin 9
int servoPinY = 10;   // Servo Y connected to digital pin 10

void setup() {
  // Attach the servos to their respective pins
  servoX.attach(servoPinX);
  servoY.attach(servoPinY);

  pinMode(joystickX, INPUT);    // Set joystick X-axis as input
  pinMode(joystickY, INPUT);    // Set joystick Y-axis as input
}

void loop() {
  // Read the X-axis and Y-axis values from the joystick
  int xVal = analogRead(joystickX);   // Read the X-axis value (0 to 1023)
  int yVal = analogRead(joystickY);   // Read the Y-axis value (0 to 1023)

  // Map the joystick values to a range for the servo (0 to 180 degrees)
  int servoXAngle = map(xVal, 0, 1023, 0, 180);  // For servo X
  int servoYAngle = map(yVal, 0, 1023, 0, 180);  // For servo Y

  // Set the servos to the mapped angles
  servoX.write(servoXAngle);   // Move servo X
  servoY.write(servoYAngle);   // Move servo Y

  delay(15);   // Small delay for smooth servo movement
}

