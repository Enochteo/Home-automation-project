from flask import Flask, render_template, request, jsonify

app = Flask(__name__)

sensor_data = {"temperature": 0, "Humidity": 0, "light":0}
device_states = {"light": False}

@app.route("/")
def index():
    return render_template("home.html")

@app.route("/update", methods=["POST"])
def update_sensor():
    data = request.json
    sensor_data.update(data)
    return jsonify({"status": "success"}), 200

@app.route("/status")
def det_status():
    return jsonify(sensor_data | device_status)


@app.route("/toggle/<device>")
def toggle_device(device):
    if device in device_states:
        device_states[device] = not device_states[device]
    return jsonify({device: device_states[device]})