#include <Servo.h>

Servo servo1;  // Create Servo objects
Servo servo2;
Servo servo3;

// Pin assignments
int joystickX = A0;   // Joystick X-axis connected to analog pin A0
int buttonPin = 2;    // Joystick button connected to digital pin 2

int servoPin1 = 9;    // Servos connected to digital pins
int servoPin2 = 10;
int servoPin3 = 11;

int currentServo = 0; // 0: all servos, 1: servo1, 2: servo2, 3: servo3
bool buttonPressed = false;  // To detect button presses

void setup() {
  // Attach the servos to their respective pins
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);

  pinMode(joystickX, INPUT);    // Set joystick X-axis as input
  pinMode(buttonPin, INPUT_PULLUP);  // Set joystick button as input with internal pull-up resistor
}

void loop() {
  int joystickVal = analogRead(joystickX);   // Read the X-axis value
  int servoAngle = map(joystickVal, 0, 1023, 0, 180);  // Map to 0-180 degrees for the servo

  // Check if the button is pressed (active LOW)
  if (digitalRead(buttonPin) == LOW && !buttonPressed) {
    buttonPressed = true;
    currentServo++;  // Switch to the next servo
    if (currentServo > 3) {
      currentServo = 0;  // Cycle through servos and reset to 0
    }
    delay(200);  // Debounce delay to avoid multiple presses
  }

  // Check when the button is released
  if (digitalRead(buttonPin) == HIGH && buttonPressed) {
    buttonPressed = false;
  }

  // Control the servos based on the current selection
  if (currentServo == 0) {
    // Move all servos
    servo1.write(servoAngle);
    servo2.write(servoAngle);
    servo3.write(servoAngle);
  } else if (currentServo == 1) {
    // Move only servo 1
    servo1.write(servoAngle);
  } else if (currentServo == 2) {
    // Move only servo 2
    servo2.write(servoAngle);
  } else if (currentServo == 3) {
    // Move only servo 3
    servo3.write(servoAngle);
  }

  delay(15);  // Small delay for smooth servo movement
}
