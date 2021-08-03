#include <LiquidCrystal.h>

float tempC; // Para almacenar temp en °C
int sensRead; // Para alamcenar la lectura analogica (0 a 1023) del sensor
const int sensor = A0;

LiquidCrystal lcd(12,11,5,4,3,2);
  
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop()
{
  sensRead = analogRead(sensor);
  tempC = map(sensRead,0,1023,0,5000); // Uso de funcion MAP para transformar valores analaogico a mV
  tempC = (tempC-500)/10; // El datasheet del sensor TMP36 (no LM35) muestras que esta es la formula correcta para obtener el valor en °C

  
  lcd.setCursor(0,0);
  lcd.print("Temperatura:");
  lcd.setCursor(0,1);
  lcd.print(tempC);
  delay(1000);
}
