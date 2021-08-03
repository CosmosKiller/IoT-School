// Código para esclavo ESP8266 con sensore mq135 y dht22

#include "ESP8266WiFi.h"
#include <aREST.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>

//def
#define DHTPIN D2
#define DHTTYPE DHT22
#define MQ A0

//Init
DHT dht(DHTPIN, DHTTYPE);

//aREST
aREST rest = aREST();

//WiFi
const char* ssid = "Fibertel WiFi268 2.4GHz";
const char* password = "0043669392";

//Port
#define LISTEN_PORT 80

//Server
WiFiServer server(LISTEN_PORT);

//Variales API
float mq, humidity, temperature;

void setup() {
  Serial.begin(9600);
  dht.begin();
  
//Init Var API
  rest.variable("temperature",&temperature);
  rest.variable("humidity",&humidity);
  rest.variable("polution",&mq);
  
//ID
  rest.set_id("0");
  rest.set_name("sensor_MCU");

//WiFi Connection
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Conectado!");

//Server Init
  server.begin();
  Serial.println("Servidor Iniciado");

//IP
  Serial.println(WiFi.localIP());
}

void loop() {
  //Espera
  delay(1000);
  mq = analogRead(MQ); //MQ135
  humidity = dht.readHumidity(); //Humedad Relativa
  temperature = dht.readTemperature(); //De 0°C a 100°C

  //Rest Calls
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  while (!client.available()) {
    delay(1);
  }
  rest.handle(client);
}
