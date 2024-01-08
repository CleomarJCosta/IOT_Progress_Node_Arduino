#include <DHT.h>//Inclui a biblioteca DHT Sensor Library
#define DHTPIN 5//Pino digital 2 conectado ao DHT11
#define DHTTYPE DHT11//DHT 11

DHT dht(DHTPIN, DHTTYPE);//Inicializando o objeto dht do tipo DHT passando como parâmetro o pino (DHTPIN) e o tipo do sensor (DHTTYPE)

void setup() {
  Serial.begin(9600);//Inicializa a comunicação serial
  dht.begin();//Inicializa o sensor DHT11
}

void loop() {
  delay(2000);//Intervalo de dois segundos entre as medições

  float humidade = dht.readHumidity();//lê o valor da umidade e armazena na variável h do tipo float 
  float temperatura = dht.readTemperature();//lê o valor da temperatura e armazena na variável t do tipo float 

  if (isnan(humidade) || isnan(temperatura)) {//Verifica se a umidade ou temperatura são ou não um número
    return;//Caso não seja um número retorna
  }

  Serial.print("Umidade:");
  Serial.println(humidade);
  Serial.print("Temperatura:");
  Serial.println(temperatura);

  delay(1000);  // Add a delay to avoid flooding the serial port
}