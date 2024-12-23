# Winter 2024 Projects

This Repository holds the Projects I did over Winter Break 2024. The Final Project is incomplete due to the 12C Safe Level Shifters not coming in in time :(. When they do come in, I will update the Repo with a final video!

## Table of Contents
- [Final Project](https://github.com/Bunga-byte/Winter2024/tree/main/Final%20Project)
- [Joystick Proof](https://github.com/Bunga-byte/Winter2024/tree/main/Joystick%20Proof)
- [Servo Proof](https://github.com/Bunga-byte/Winter2024/tree/main/Servo%20Proof)
- [Turret Proof](https://github.com/Bunga-byte/Winter2024/tree/main/Turret%20Proof)

## Overview
- Final Project:<br>
  The Final Project takes all three proofs and combines them into one main system. The Final Project uses additional ESP32s to have WiFi capabilites. So, as long    as both ESP32s are on same the WiFi, you can control the Turret from anywhere!
- Joystick Proof:<br>
  The Joystick Proof uses the Joystick, Arduino Uno, and LEDs to prove that the Joystick works like intended. Using the Joystick X-Value you can control the    brightness of the LEDs, and the Push Button on the JoyStick controls which LED you are using.
- Servo Proof:<br>
  The Servo Proof uses the Joystick and Servos to prove that the Servos and Joystick work together. Using the Joystick, you can control the rotation of the servo, 
  and using the Push Button on the Joystick, you can control which Servo you control.
- Turret Proof:<br>
  The Turret Proof uses the previous Proofs to create a functioning Turret. It uses the Joystick and 2 Servos. The 2 Servos act as the X and Y axis of the Turret. 

## Hardware Used
The following components are used in this project:
- **Arduino Uno/Mega**: Microcontrollers to control the system.
- **ESP32**: Used for WiFi Capabilities.
- **Servo**: Used to control movement of Turret
- **Joystick**: Used for X and Y data, and Push Button
- **Level Shifter**: Used to Shift voltages from 3.3V - 5V and from 5V - 3.3V. Due to the ESP32 using 3.3V and the Arduinos using 5V.
- **Power Supply**: Appropriate power for the Servos.
- **Cardboard**: The material used to create the Turret.

## Schematic Final System
Here is a screenshot of the schematic that illustrates how the components are connected:

![Schematic Screenshot](https://github.com/Bunga-byte/Winter2024/blob/main/Final%20Project/Final%20System.png)

The full schematic file is also available in this repository as `FinalSystem.fzz` in the Final Project Folder.
The best way to think about the system is like this: Joystick -> Arduino Mega -> First ESP32 -> Second ESP32 -> Arduino Uno -> Servo Turret

## Code Final System
- The Arduino Uno code to control the Servos based on the TX Data from the Second ESP32, `ArduinoUnoServo.ino` in the Final Project Folder.<br>
- The Arduino Mega code to take in the Joystick Data and send to the RX Data of the First ESP32, `ArduinoMegaJoystick.ino` in the Final Project Folder.<br>
- The First ESP32 code to take in the TX Data from the Arduino Mega and transmit the Data to the Second ESP32, `FirstESP32.ino` in the Final Project Folder.<br>
- The Second ESP32 code to take in the transmitted Joystick code and send it to the Arduino Uno RX Data, `SecondESP32.ino` in the Final Project Folder.<br>


## Proof Videos
For the Proofs, I took videos showing their fuctionality. <br>
- [Joystick Proof Video](https://drive.google.com/file/d/1QfWjBV0AonXzMbsJbF9MJua1zJsgnPCm/view?usp=sharing)
- [Servo Proof Video](https://drive.google.com/file/d/1b3VGC-HKR39C-DVepIYNn68QBVo1b7Tz/view?usp=sharing)
- [Turret Proof Video](https://drive.google.com/file/d/1PmApAlEgW--owJrROgI6_fgr3W4tIzn4/view?usp=sharing)

