# Wearable Gesture Control System for Robotic Navigation

A wearable, IMU-based gesture control system that allows for intuitive robotic navigation. This project uses an **MPU6050 (Accelerometer + Gyroscope)** to detect hand tilts, an **ESP8266** to process the data, and **ESP-NOW** protocol for low-latency wireless communication to a receiving robot.

## 🚀 Features
* **Low Latency:** Uses ESP-NOW protocol (faster than standard Wi-Fi or Bluetooth).
* **Precision Control:** MPU6050 provides 6-axis motion sensing for smooth navigation.
* **Wireless & Wearable:** Compact design suitable for a glove or wristband.
* **Energy Efficient:** Optimized for battery-powered wearable operation.

---

## 🏗 System Architecture

### Block Diagram
<img width="760" height="467" alt="image" src="https://github.com/user-attachments/assets/f12fc878-8222-4871-9b86-1fb1f493837d" />


*The wearable unit (Transmitter) captures motion and sends data packets via ESP-NOW to the Robot Controller (Receiver).*

### Logic Flowchart
<img width="324" height="484" alt="image" src="https://github.com/user-attachments/assets/91f4b41a-089e-456b-a7e9-0f5ac5356d28" />

*The firmware follows a loop of sensing, threshold calculation, and wireless transmission.*

### Circuit/Pin Connections (Transmitter)
![Pin Diagram](Diagrams/Pin_Diagram.png)

| Component | ESP8266 Pin | MPU6050 Pin |
|-----------|-------------|-------------|
| VCC       | 3.3V        | VCC         |
| GND       | GND         | GND         |
| SCL       | D1 (GPIO5)  | SCL         |
| SDA       | D2 (GPIO4)  | SDA         |

---

## 🛠 Hardware Requirements
* **Transmitter:** ESP8266 (NodeMCU/Wemos D1 Mini), MPU6050 IMU.
* **Receiver:** ESP8266, L298N Motor Driver, Robot Chassis.
* **Power:** 3.7V Li-ion battery (Wearable) / 7.4V-12V (Robot).

## 💻 Software & Libraries
* **Language:** C++ (Arduino IDE)
* **Libraries:**
    * `espnow.h` & `ESP8266WiFi.h`
    * `Adafruit_MPU6050`
    * `Adafruit_Sensor`

## 🔧 Installation & Setup
1.  **MAC Address:** Run a "MAC Address Finder" sketch on your **Receiver** ESP8266.
2.  **Configuration:** Replace the `receiverAddress[]` in the Transmitter code with your receiver's MAC address.
3.  **Upload:** Flash the Transmitter code to the wearable unit and Receiver code to the robot.
4.  **Calibrate:** Ensure the IMU is level at startup for accurate gesture mapping.

---

## 👤 Author
**Pawan Kumar**
* GitHub: [@PawankrAnand-ece](https://github.com/PawankrAnand-ece)
