## Project log
**Sat. Jun 21, 2025**
Today I connected the ESP32 to send posts to the server (sensor data) and also send get requests for the server (device state) this is to toggle an LED. I also removed id bugs from the AJAX frontend (there were issues with the promises), and also the sensor data id names on the dashboard html. Also implemented functioning of turning the LED on the ESP on.
**Notes**
- The server(my mac) ip address changes every time you restart the wifi so update the arduino code.
- Take note of json keys and id names in the templates.

**Wed. Jul 2, 2025**
Implemented graphical sensor data display on the dashboard using Charts.js, basically linked the cdn, created the canvas in the dashboard html file and updated them with the sensor data in scripts.js using DOM manipulation.
To implement:
- Resting phase for webpage when ESP32 is not connected / data is not read
- Database for data
- any form of analytics/predictions.
