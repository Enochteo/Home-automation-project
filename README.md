# Home Automation Dashboard
A web-based dashboard designed to monitor and control smart home devices in real time. This project integrates IoT hardware with a clean user interface to provide centralized control, live sensor data, and automation features for smart environments.

## Description
The Home Automation Dashboard connects with a microcontroller, ESP32 to control and monitor devices such as lights, fans, temperature sensors, and more. The system collects data from IoT devices, displays it in an intuitive dashboard, and allows users to trigger actions manually or automatically based on rules.

## Features
Real-time device status updates and control

Live sensor data (temperature, humidity, etc.)

Responsive web interface for desktop and mobile

AI device Automation

Secure user authentication (to be added)

Modular and extensible device support

## Tech Stack
Frontend: HTML, CSS, JavaScript (optional React upgrade)

Backend: Flask (Python)

Microcontroller: ESP32 WROOM Dev Board

Database: SQLite or Firebase (for cloud sync)

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


## Why the AI device automation model?
Home automation systems must be robust, adaptive, and responsive to both extreme environmental conditions and personal user preferences. Traditional rule-based systems rely on fixed thresholds (e.g., "turn on light if light level < 300"), which fail to account for real-world complexity such as Seasonal variations in ambient lighting and humidity, Changes in user comfort over time, Dynamic conditions (e.g., cloudy days, heat waves, indoor activities), This is where machine learning provides a smarter alternative.

By training a model on historical data — including temperature, humidity, and ambient light levels, along with user preferences — the system learns when to activate devices (like lights or fans) without being explicitly told. This allows it to make personalized, real-time decisions that align with the user’s habits and the environmental context.

Imagine a system that automatically adjusts lighting and temperature in your home — not based on fixed thresholds, but on your past behavior, the season, time of day, and indoor conditions. That’s the kind of intelligent automation this project aims to deliver.

Contributing
Contributions and suggestions are welcome. 
