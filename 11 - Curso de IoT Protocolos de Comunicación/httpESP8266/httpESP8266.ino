#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti wifimulti;
void setup()
{
  Serial.begin(9600);
  delay(1000);
  WiFi.mode(WIFI_STA);
  WiFi.begin("Fibertel WiFi268 2.4GHz","0043669392");
  wifimulti.addAP("Fibertel WiFi268 2.4GHz","0043669392");

  Serial.println("Conectando...");
  while((WiFi.status() == WL_CONNECTED))
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Conectado!");
  Serial.println("Dirección IP:");
  Serial.println(WiFi.localIP());

}

void loop()
{
  if((wifimulti.run() == WL_CONNECTED))
  {
      WiFiClient client;
      HTTPClient http;
      Serial.println("[HTTP] Iniciando...");
      http.begin(client,"http://www.arduino.cc/asciilogo.txt");
    
      Serial.println("[HTTP] Get...");
      http.GET();
      String respuesta = http.getString();
      Serial.print(respuesta);
      http.end();
      delay(10000);
  }
}
