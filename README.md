# Arduino Sonar System

A 180° sweep object tracking radar using an Arduino Uno (R3). Distance measurement mapped directly onto an 8x8 MAX7219 LED matrix display.

# Features

- Radar Sweep: Continuous 0° to 180° tracking powered by an SG99 servo motor
- Visualization: Dynamic object position mapping on an 8x8 LED matrix display

# Components

- Controller: Arduino Uno R3
- Actuator: SG90 Micro Servo Motor
- Sensor: HC-SR04 Ultrasonic Sensor
- Display: MAX7219 8x8 LED Matrix Module

# Software & Libraries

- Environment: Arduino IDE
- Firmware Language: C++
- Libraries:
  - <Servo.h> for motor angular sweep control
  - <LedControl.h> for MAX7219 SPI display driving

# How It Works

1. The servo performs a smooth sweep loop from 0° to 180° and back.
2. The ultrasonic sensor measures the echo return time at every step and converts it to centimeters.
3. The angle is mapped across the 8 matrix columns (0°–180° -> Col 0–7).
4. The distance is mapped across the 8 matrix rows (1cm–40cm -> Row 7–0).
5. A single LED lights up on the matrix to mark the exact position of the detected object.

# Extras

Fun Project i did to learn abit about the MAX7219 aswell that ive never really used a sonar in a project.

# Extras

Exporting failures

<img width="493" height="349" alt="Screenshot 2026-10-07 175928" src="https://github.com/user-attachments/assets/86ad4213-3336-494c-a221-aad9fcdaf800" />

