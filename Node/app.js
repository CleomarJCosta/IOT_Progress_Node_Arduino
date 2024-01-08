const express = require('express');
const SerialPort = require('serialport');

const app = express();
const port = 3000;

const serialPort = new  SerialPort.SerialPort({path:"COM5", baudRate: 9600,});  // Substitua 'COM3' pela porta do seu Arduino

app.get('/dados', (req, res) => {
  let receivedData = '';

  serialPort.on('data', (data) => {
    receivedData += data.toString();

    const dataParts = receivedData.split('\n');
    if (dataParts.length >= 2) {
      const humidityMatch = dataParts[0].match(/Umidade:(\d+\.\d+)/);
      const temperatureMatch = dataParts[1].match(/Temperatura:(\d+\.\d+)/);

      if (humidityMatch && temperatureMatch) {
        const humidity = parseFloat(humidityMatch[1]);
        const temperature = parseFloat(temperatureMatch[1]);

        const responseData = { humidity, temperature };
        res.json(responseData);
        receivedData = '';

        // Remove the event listener after sending the response
        serialPort.removeAllListeners('data');
      }
    }
  });

  serialPort.write('L');
});

app.listen(port, () => {
  console.log(`Servidor rodando em http://localhost:${port}`);
});
