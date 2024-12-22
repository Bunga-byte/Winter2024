// Pin Definitions
const int ledPins[4] = {3, 5, 6, 9};  // PWM pins for LEDs
const int joyYPin = A0;               // Joystick Y-axis (analog pin)
const int buttonPin = 2;              // Joystick button (digital pin)
const int joyThreshold = 1;          // Sensitivity threshold for joystick motion

int currentLED = 0;                   // Tracks the currently selected LED (0-3)
int brightness[4] = {0, 0, 0, 0};     // Stores brightness levels for each LED
bool buttonState = LOW;               // Current state of the button
bool lastButtonState = LOW;           // Previous state of the button

void setup() {
  // Set LED pins as outputs
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Set button pin as input with pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);

  // Initialize Serial Monitor (optional)
  Serial.begin(9600);
}

void loop() {
  // Read joystick Y-axis
  int joyYValue = analogRead(joyYPin);

  // Map joystick Y-axis (0-1023) to PWM range (0-255) for brightness control
  int newBrightness = map(joyYValue, 0, 1023, 0, 255);

  // Only adjust brightness if joystick is moved beyond the threshold
  if (abs(newBrightness - brightness[currentLED]) > joyThreshold) {
    brightness[currentLED] = newBrightness;
    analogWrite(ledPins[currentLED], brightness[currentLED]);

    // Optional: Print current LED and brightness to the Serial Monitor
    Serial.print("LED ");
    Serial.print(currentLED);
    Serial.print(" brightness: ");
    Serial.println(brightness[currentLED]);
  }

  // Read button state (active LOW, so LOW means pressed)
  buttonState = digitalRead(buttonPin);

  // If button is pressed and it wasn't pressed in the previous loop
  if (buttonState == LOW && lastButtonState == HIGH) {
    // Move to the next LED (wrap around after the 4th LED)
    currentLED = (currentLED + 1) % 4;

    // Optional: Print the current LED to the Serial Monitor
    Serial.print("Switched to LED ");
    Serial.println(currentLED);
  }

  // Update the last button state for the next loop iteration
  lastButtonState = buttonState;

  // Small delay to debounce the button
  delay(50);
}
