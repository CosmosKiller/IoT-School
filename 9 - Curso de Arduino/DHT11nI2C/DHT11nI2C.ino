#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2 //Pin digital para sensor
#define DHTTYPE DHT11 //Sensor DHT11

float temp;
float hum;
float tempNow = 0; 

LiquidCrystal_I2C lcd(0x3f,16,2); //Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
DHT dht(DHTPIN, DHTTYPE); // Crear objeto dht con los parametros antes definidos

void setup() 
{
  Serial.begin(9600);
  dht.begin(); //Inicializa sensor
  lcd.init();  // Inicializar el LCD
  lcd.backlight();  //Encender la luz de fondo
  

}

void loop() 
{
  hum= dht.readHumidity(); //Humedad Relativa
  temp = dht.readTemperature(); //De 0°C a 100°C
  
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(5,0);
  lcd.print(temp); // En esta parte mostramos la primer lectura
  lcd.setCursor(10,0);
  lcd.print(char(223)); // Simbolo de ° en ASCII
   lcd.setCursor(11,0);
  lcd.print("C");

  lcd.setCursor(0,1);
  lcd.print("Humedad:"); // Ya que el DHT11 lo trae incorporado, demosle uso
  lcd.setCursor(8,1);
  lcd.print(hum);
  lcd.setCursor(13,1);
  lcd.print("%");

  

  if (temp > tempNow) // Condición si la temperatura sube
  { 
    lcd.clear(); 
    lcd.print("Temp:");
    lcd.setCursor(5,0);
    lcd.print(temp);
    lcd.setCursor(10,0);
    lcd.print(char(223));
    lcd.setCursor(11,0);
    lcd.print("C - Subiendo");
    tempNow = temp; // Almacenamos la temperatura "actual" 
  }
  else if (temp < tempNow) // Condición si la temperatura sube
  {
    lcd.clear();
    lcd.print("Temp:");
    lcd.setCursor(5,0);
    lcd.print(temp);
    lcd.setCursor(10,0);
    lcd.print(char(223));
    lcd.setCursor(11,0);
    lcd.print("C - Bajando");
    tempNow = temp; // Almacenamos la temperatura "actual" 
  }
  else
  
  lcd.scrollDisplayLeft(); 
 
  delay(1000);
}
