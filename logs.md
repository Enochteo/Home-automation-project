## Project log
**Sat. Jun 21, 2025**
Today I connected the ESP32 to send posts to the server (sensor data) and also send get requests for the server (device state) this is to toggle an LED. I also removed id bugs from the AJAX frontend (there were issues with the promises), and also the sensor data id names on the dashboard html. Also implemented functioning of turning the LED on the ESP on.
**Notes**
- The server(my mac) ip address changes every time you restart the wifi so update the arduino code.
- Take note of json keys and id names in the templates.
