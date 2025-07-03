# Home Automation Dashboard
A web-based dashboard designed to monitor and control smart home devices in real time. This project integrates IoT hardware with a clean user interface to provide centralized control, live sensor data, and automation features for smart environments.

## Description
The Home Automation Dashboard connects with a microcontroller, ESP32 to control and monitor devices such as lights, fans, temperature sensors, and more. The system collects data from IoT devices, displays it in an intuitive dashboard, and allows users to trigger actions manually or automatically based on rules.

## Features
Real-time device status updates and control

Live sensor data (temperature, humidity, etc.)

Responsive web interface for desktop and mobile

Automation logic (e.g., turn lights on when dark)

Secure user authentication (to be added)

Modular and extensible device support

## Tech Stack
Frontend: HTML, CSS, JavaScript 

Backend: Flask (Python)

Microcontroller: ESP32 WROOM Dev Board

Database: Firebase - for cloud sync (to be added)

Other: HTTP (later MQTT) for device communication, Chart.js for data visualization

<!--## Folder Structure

```
home-automation-dashboard/
│
├── static/               # CSS, JavaScript, images
├── templates/            # HTML pages (Jinja2)
├── devices/              # ESP32/Arduino code
├── app.py                # Flask backend
├── models.py             # Data models
├── utils/                # Automation logic and API handlers
├── requirements.txt      # Python dependencies
└── README.md
```-->
## Demo and Screenshots
<img width="1434" alt="Dashboard-Homepage-1" src="https://github.com/user-attachments/assets/07294daf-190c-4b3f-bcb6-6f9b8b4596c3" />
<img width="1437" alt="Dashboard-Homepage-2" src="https://github.com/user-attachments/assets/f9631a2a-c526-4132-b93a-da2a0887d2a0" />



Contributing
Contributions and suggestions are welcome. 
