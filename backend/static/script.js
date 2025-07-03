async function fetchStatus() {
    try {
    // promises for data and status
    const res =  await fetch('/status');
    const data = await res.json();
    // update webpage
    document.getElementById('temp').textContent = data.temperature
    document.getElementById('humid').textContent = data.humidity;
    document.getElementById('lightData').textContent = data.lightData;
    document.getElementById('lightState').textContent = data.lightState? 'ON' : 'OFF';  
    updateCharts(data); 
    } catch (err){
        console.error("Error fetching data:", err);
    }
    
}

async function toggleDevice(device) {
    await fetch(`/toggle/${device}`);
    fetchStatus();
}

setInterval(fetchStatus, 2000);
fetchStatus();

const tempData = [];
const humidityData = [];
const lightData = [];
const labels = [];

const maxPoints = 20; // max data points visible

const createChart = (ctxId, label, data, borderColor) => {
    return new Chart(document.getElementById(ctxId), {
        type: 'line',
        data: {
            labels: labels,
            datasets: [{
                label: label,
                data: data,
                borderColor: borderColor,
                tension: 0.4,
                fill: false
            }]
        },
        options: {
            animation: false,
            responsive: true,
            scales: {
                x: {
                    display: true,
                    title: { display: true, text: 'Time' }
                },
                y: {
                    beginAtZero: true
                }
            }
        }
    });
};

const tempChart = createChart("tempChart", "Temperature (°C)", tempData, "red");
const humidityChart = createChart("humidityChart", "Humidity (%)", humidityData, "blue");
const lightChart = createChart("lightChart", "Light Level", lightData, "orange");

function updateCharts(data){
    const timestamp = new Date().toLocaleTimeString();

    if (labels.length >= maxPoints){
        labels.shift();
        tempData.shift();
        humidityData.shift();
        lightData.shift();
    }
    labels.push(timestamp);
    tempData.push(data.temperature);
    humidityData.push(data.humidity);
    lightData.push(data.lightData);

    tempChart.update();
    humidityChart.update();
    lightChart.update();
}