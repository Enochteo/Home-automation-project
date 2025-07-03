from flask import Flask, render_template, request, jsonify

app = Flask(__name__)

sensor_data = {"temperature": 0, "humidity": 0, "lightData": 0}
device_states = {"lightState": False}

@app.route("/")
def index():
    return render_template("dashboard.html")

@app.route("/update", methods=["POST"])
def update_sensor():
    data = request.get_json()
    if data:
        print(f"Received: {data}")
        sensor_data.update(data)
        return jsonify({"status": "success"}), 200
    else:
        return jsonify({"error": "Invalid JSON"}), 400
    
@app.route("/status")
def det_status():
    return jsonify(sensor_data | device_states)


@app.route("/toggle/<device>")
def toggle_device(device):
    if device in device_states:
        device_states[device] = not device_states[device]
    return jsonify({device: device_states[device]})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5001, debug=True)
