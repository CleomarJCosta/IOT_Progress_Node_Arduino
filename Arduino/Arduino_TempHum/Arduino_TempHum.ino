//Projeto medir a temperatura e a umidade com DHT11
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

  float h = dht.readHumidity();//lê o valor da umidade e armazena na variável h do tipo float (aceita números com casas decimais)
  float t = dht.readTemperature();//lê o valor da temperatura e armazena na variável t do tipo float (aceita números com casas decimais)

  if (isnan(h) || isnan(t)) {//Verifica se a umidade ou temperatura são ou não um número
    return;//Caso não seja um número retorna
  }

  Serial.print("Umidade:");
  Serial.println(h);
  Serial.print("Temperatura:");
  Serial.println(t);

  delay(1000);  // Add a delay to avoid flooding the serial port
}