const int motor1A = 4; // A entrada 1
const int motor1B = 2; // A entrada 2
const int velocidad = 5; // PWM para regular velocidad
const int btn = 11; // Botón para cambiar sentido de giro

int potPin = A0; // Entrada análoga para cambiar manualmente la velocidad
int potValue = 0; // Valor de lectura del potenciómetro, inicializado en 0
int speed; // Velocidad del motor
int estado = 1; // Sentido de giro

void setup()
{
  //Definimos nuestros pines
	pinMode(motor1A, OUTPUT);
	pinMode(motor1B, OUTPUT);
	pinMode(btn, INPUT_PULLUP);
 
}

void loop()
{
    // Leemos el valor del A0, podemos variarlo con el potenciómetro
  	potValue = analogRead(potPin); 
  	/* Usamos la función map, que es básicamente una regla de 3 simple,
  	para transformar los valores analógico a valores PWM */
  	speed = map(potValue,0,1023,0,255); 
  	
   	/* Dependiendo del "estado" el motor girara para una lado
       o para el otro*/
  	if ( estado == 0)
    {
    	digitalWrite(motor1A, HIGH);
  		digitalWrite(motor1B, LOW);
    }
  	else // Sería estado = 1
    {
      	digitalWrite(motor1A, LOW);
  		digitalWrite(motor1B, HIGH);
    }
  	analogWrite(velocidad, speed); //Le indicamos la velocidad al motor

  
  	/* Aqui es donde podemos cambiar el sentido de giro del motor.
    Según el estado en el que está el motor, cuando oprimamos el 
    botón, el motor se detendrá por 2 segundos y comenzará a girar
    en sentido contrario.*/
  	if (estado == 0 && digitalRead(btn) == LOW)
    {
      	digitalWrite(motor1A, LOW);
 		digitalWrite(motor1B, LOW);
  		delay(2000);
      	estado = 1;
    }
  	else if (estado == 1 && digitalRead(btn) == LOW)
    {
      	digitalWrite(motor1A, LOW);
 		digitalWrite(motor1B, LOW);
  		delay(2000);
      	estado = 0;
    }
}