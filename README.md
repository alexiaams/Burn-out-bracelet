# Burn Out Bracelet

![Arduino](https://img.shields.io/badge/Arduino-Project-informational)
![Status](https://img.shields.io/badge/Status-Prototype-yellow)
![Made with](https://img.shields.io/badge/Made%20with-C%2B%2B-blue)

An Arduino-powered smart bracelet that monitors **temperature**, **stress levels**, and **heart rate**  
to help prevent burnout with vibration alerts, LED breathing exercises, and real-time feedback.

---

## 🌟 About the Project
This was **my first experience with Arduino** and was built as part of **Builders 101**,  
a program supported by **Launch Romania** and **How to Web**.

The bracelet combines multiple sensors to remind the user to take breaks, breathe, or move—  
helping reduce stress and avoid burnout.

---

## ✨ Features
- **Temperature & Stress Monitoring** – DS18B20 and Grove GSR sensors.
- **Break Alerts** – Soft pulsing buzzer and vibration when thresholds are exceeded.
- **Breathing Exercise** – LED guides a 4-7-8 breathing pattern.
- **Future Mobile App** – Notifications, Pomodoro timer, daily/weekly summaries.

---

## 🔮 Future Features
- Bluetooth link with a companion mobile app for real-time data.
- Customizable vibration/LED alert patterns.
- Cloud data logging and long-term analytics.
- Heart-rate variability (HRV) monitoring.

---

## 🔌 Pinout / Wiring

| Component              | Arduino Pin | Notes                                      |
|------------------------|-----------:|--------------------------------------------|
| DS18B20 (Temp) Data    | 4          | +4.7 kΩ pull-up to 5 V/3.3 V               |
| RGB LED (PWM)          | 10         | Adjust pins as needed in code              |
| Push Button            | 2          | INPUT (with pull-up/down)                  |
| Buzzer                 | 9          | Used with `tone()`                         |
| Vibration Motor        | via MOSFET | Any digital pin, external power recommended |
| GSR Sensor             | A0/A1      | Depends on module                           |
| MAX30102 (Heart Rate)  | SDA/SCL    | I²C                                        |
| Bluetooth Module       | TX/RX      | For future mobile app                       |

---

## 🛠️ Hardware
- Arduino-compatible board  
- DS18B20 temperature sensor  
- Grove GSR Sensor  
- MAX30102 heart-rate sensor  
- RGB LED  
- Coin vibration motor + MOSFET  
- Push button  
- Bluetooth module (future)

---

## 💻 Code
Main sketch: [`code/burnout_bracelet.ino`](code/burnout_bracelet.ino)

