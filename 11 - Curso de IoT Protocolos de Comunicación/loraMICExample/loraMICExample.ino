#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>
#include <DHTesp.h>
#include <CayenneLPP.h>

#define DHTPIN 23 //Pin DHT22


DHTesp dht;
CayenneLPP lpp(51);

uint8_t NWSK[16] = { 0x87, 0x96, 0x49, 0xD0, 0x1C, 0x12, 0x0A, 0x03, 0x19, 0xBC, 0x4C, 0x70, 0x65, 0xB9, 0xC7, 0xD9 };
uint8_t APPSKEY[16] = { 0x28, 0x58, 0x38, 0x24, 0x76, 0x1E, 0x8C, 0x73, 0x9F, 0xAA, 0xC5, 0x7D, 0x0C, 0xE1, 0xCD, 0x23 };
uint32_t DEVADDR = 0x26031FD7;

void os_getArtEui(u1_t* buf){}
void os_getDevEui(u1_t* buf){}
void os_getDevKey(u1_t* buf){}

const unsigned TX_INTERVAL = 10;
unsigned long previousMillis = 0;

const lmic_pinmap lmic_pins = {
  .nss = 18,
  .rxtx = LMIC_UNUSED_PIN,
  .rst = 14,
  .dio = { 26, 33, 32} 
};

void onEvent(ev_t ev)
{
  switch(ev)
  {
   case EV_TXCOMPLETE:
   Serial.println("[LMIC] Radio TX complete");
   digitalWrite(LED_BUILTIN,LOW);
   break;
   default:
   Serial.println("Evento desconocido");
   break;
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.println("[INFO] Iniciando...");
  pinMode(LED_BUILTIN,OUTPUT);
  dht.setup(DHTPIN,DHTesp::DHT22);
  os_init();
  LMIC_reset();
  LMIC_setSession(0x1,DEVADDR,NWSK,APPSKEY);

  for (int chan=0;chan<72;++chan)
  {
    LMIC_disableChannel(chan);
  }
  // 904.3 Mhz banda de 915 Mhz 902-928 Mhz
  LMIC_enableChannel(10);
  LMIC_setLinkCheckMode(0);
  LMIC_setDrTxpow(DR_SF7,20);

  previousMillis = millis();
}

void loop()
{
  if(millis()>previousMillis+(TX_INTERVAL*1000))
  {
    getInfoAndSend();
    previousMillis = millis();
  }
  os_runloop_once();
}

void enviarDatos(uint8_t *mydata, uint16_t len)
{
  if(LMIC.opmode & OP_TXRXPEND)
  {
    Serial.println("[LMIC] OP_TXRXPEND, not sending");
  }
  else
  {
    LMIC_setTxData2(1,mydata,len,0);
  }
}

void getInfoAndSend()
{
   digitalWrite(LED_BUILTIN,HIGH);
  //Leer sensores y trasmitir
  float t = dht.getTemperature();
  float h = dht.getHumidity();

  lpp.addTemperature(1, t);

  enviarDatos(lpp.getBuffer(),lpp.getSize());
}
