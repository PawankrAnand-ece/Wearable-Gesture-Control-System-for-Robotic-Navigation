# Pin Mapping  
**Project:** Wearable Gesture Control System for Robotic Navigation

This document describes the pin connections between ESP8266 NodeMCU and all peripherals.

---

## 📡 Wearable Gesture Unit (Transmitter)

### MPU6050 IMU Sensor → ESP8266 NodeMCU

| MPU6050 Pin | ESP8266 Pin | GPIO | Description |
|-----------|------------|------|-------------|
| VCC | 3.3V | — | Power supply |
| GND | GND | — | Ground |
| SDA | D2 | GPIO4 | I²C Data |
| SCL | D1 | GPIO5 | I²C Clock |
| INT | Not Used | — | Interrupt (optional) |

---

## 🚗 Robot Unit (Receiver)

### Right Motor Driver Connections

| Motor Driver Pin | ESP8266 Pin | GPIO |
|----------------|------------|------|
| IN1 | D1 | GPIO5 |
| IN2 | D2 | GPIO4 |
| IN3 | D5 | GPIO14 |
| IN4 | D6 | GPIO12 |

---

### Left Motor Driver Connections

| Motor Driver Pin | ESP8266 Pin | GPIO |
|----------------|------------|------|
| IN1 | D7 | GPIO13 |
| IN2 | D8 | GPIO15 |
| IN3 | D3 | GPIO0 |
| IN4 | D4 | GPIO2 |

---

### Ultrasonic Sensor (HC-SR04)

| Sensor Pin | ESP8266 Pin | GPIO | Notes |
|-----------|------------|------|------|
| VCC | 5V | — | Sensor power |
| TRIG | D0 | GPIO16 | Trigger pulse |
| ECHO | RX | GPIO3 | Use voltage divider (5V → 3.3V) |
| GND | GND | — | Ground |

---

## ⚠ ESP8266 Boot-Safety Notes (IMPORTANT)

| Pin | Boot State |
|----|-----------|
| GPIO0 (D3) | HIGH |
| GPIO2 (D4) | HIGH |
| GPIO15 (D8) | LOW |

✔ Ensure motor driver inputs do not pull these pins incorrectly during boot.

---

## ✅ Best Practices
- Always use **common ground**
- Avoid using GPIO0, GPIO2, GPIO15 for high-load signals
- Add decoupling capacitors near motor driver
- Use short wires for I²C lines

---
