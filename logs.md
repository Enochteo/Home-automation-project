## Project log
**Sat. Jun 21, 2025**
Today I connected the ESP32 to send posts to the server (sensor data) and also send get requests for the server (device state) this is to toggle an LED. I also removed id bugs from the AJAX frontend (there were issues with the promises), and also the sensor data id names on the dashboard html. Also implemented functioning of turning the LED on the ESP on.
**Notes**
- The server(my mac) ip address changes every time you restart the wifi so update the arduino code.
- Take note of json keys and id names in the templates.

**July 14, 2025**
The next feature for this project is an ML model (binary classifier) that would learn from sensor data to activate two actuators (LED for light, Mini fan for temperature and cooling) based on patterns from the sensor data (could be weather conditions, user preference, threshold values).
Steps / Integrations for AI model
- Python script to log sensor data to csv
- Model training and testing on Jupyter
- model deployment
- model integration in flask server
- Fetch status and display on web

Why the model?
Home automation systems must be robust, adaptive, and responsive to both extreme environmental conditions and personal user preferences. Traditional rule-based systems rely on fixed thresholds (e.g., "turn on light if light level < 300"), which fail to account for real-world complexity such as Seasonal variations in ambient lighting and humidity, Changes in user comfort over time, Dynamic conditions (e.g., cloudy days, heat waves, indoor activities), This is where machine learning provides a smarter alternative.

By training a model on historical data — including temperature, humidity, and ambient light levels, along with user preferences — the system learns when to activate devices (like lights or fans) without being explicitly told. This allows it to make personalized, real-time decisions that align with the user’s habits and the environmental context.

Imagine a system that automatically adjusts lighting and temperature in your home — not based on fixed thresholds, but on your past behavior, the season, time of day, and indoor conditions. That’s the kind of intelligent automation this project aims to deliver.
