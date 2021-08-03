int ledAnaranjado = 13;
int ledAzul = 12;
int potPin = A0;
int potValue = 0;

void setup()
{
  pinMode(ledAnaranjado, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{ 
  potValue = analogRead(potPin);
  Serial.println(potValue);
  
  digitalWrite(ledAnaranjado, HIGH);
  digitalWrite(ledAzul, LOW);
  delay(potValue);
  digitalWrite(ledAnaranjado, LOW);
  digitalWrite(ledAzul, HIGH);
  delay(potValue);
}
