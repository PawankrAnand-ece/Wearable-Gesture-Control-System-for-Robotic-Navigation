# Components List  
**Project:** Wearable Gesture Control System for Robotic Navigation

This document lists all hardware components used in the project along with their purpose.

---

## 🔧 Core Components

| Component | Quantity | Purpose |
|---------|---------|--------|
| ESP8266 NodeMCU | 2 | One for wearable gesture unit (transmitter) and one for robot unit (receiver) |
| MPU6050 IMU Sensor | 1 | Detects hand gesture using accelerometer & gyroscope |
| Motor Driver (L298N / L293D) | 1 | Drives DC motors based on control signals |
| DC Motors | 2 / 4 | Robot movement |
| HC-SR04 Ultrasonic Sensor | 1 | Obstacle detection & collision avoidance |

---

## 🔋 Power Components

| Component | Quantity | Purpose |
|---------|---------|--------|
| Battery Pack (7.4V / 12V) | 1 | Power supply for robot |
| Voltage Regulator / Buck Converter | 1 | Regulates voltage for ESP8266 |
| USB Cable | 1 | Programming and debugging |

---

## 🔌 Miscellaneous

| Component | Quantity | Purpose |
|---------|---------|--------|
| Jumper Wires (Male–Female) | As required | Connections |
| Resistors (1kΩ, 2kΩ) | 2 | Voltage divider for ultrasonic ECHO pin |
| Breadboard / PCB | 1 | Prototyping |
| Wearable Glove / Band | 1 | Mounting MPU6050 sensor |

---

## ⚠ Notes
- ESP8266 operates at **3.3V logic level**
- HC-SR04 ECHO pin outputs **5V**, so a voltage divider is mandatory
- Common ground must be shared between ESP8266 and motor driver

---
