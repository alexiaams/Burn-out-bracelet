# Burn Out Bracelet

An Arduino-powered smart bracelet that monitors **heart rate**, **temperature**, and **stress levels**,  
helping users prevent burnout through vibration alerts, LED breathing exercises, and real-time feedback.

---

## 🌟 About the Project
This project was my **first experience with Arduino** and was developed as part of **Builders 101**,  
a program supported by **Launch Romania** and **How to Web**.

The bracelet combines multiple sensors to monitor vital signs and remind the user
to take breaks, perform breathing exercises, or move around—aiming to reduce stress and avoid burnout.

---

## ✨ Features
- **Temperature & Stress Monitoring** – DS18B20 temperature sensor and GSR stress sensor.
- **Break Alerts** – Soft pulsing buzzer and vibration when temperature or stress exceeds a threshold.
- **Breathing Exercise** – LED guides a 4-7-8 breathing pattern.
- **Mobile App Integration (planned)** – For notifications, Pomodoro timer, and daily/weekly summaries.

---

## 🔮 Future Features
- Bluetooth connection with a dedicated mobile app for real-time data display.
- Customizable vibration/LED alert patterns based on personal thresholds.
- Integration with cloud services for long-term data tracking and analysis.
- Optional heart-rate variability (HRV) monitoring for deeper stress insights.

---

## 🛠️ Hardware
- Arduino-compatible board  
- DS18B20 temperature sensor  
- Grove GSR Sensor (for stress)  
- MAX30102 heart-rate sensor  
- RGB LED  
- Coin vibration motor + MOSFET  
- Push button  
- Bluetooth module (for future mobile app)

---

## 💻 Code
All Arduino code is inside the [`code/`](code/) folder.
