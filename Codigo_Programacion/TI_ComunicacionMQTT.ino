//libreria para acceder a las funciones de Cayenne
#include <CayenneMQTTESP8266.h>

//variables para la conexion de la red
char red[] = "HUAWEI Y5 2017";
char passwordWifi[] = "1234567890";

//variables que nos permien conectar con la pagina de Cayenne
char usuario[] = "123ac340-6618-11e9-933e-cf08617625ed";
char password[] = "5b8d6bf500c30debfdc1e7f66476dcefa093271b";
char clienteID[] = "a6bd1660-661f-11e9-9dd7-93e53f1934d3";


const int led = 14;
const int ventilador = 12;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(ventilador, OUTPUT);
	Cayenne.begin(usuario, password, clienteID, red, passwordWifi);
}

void loop() {
	Cayenne.loop();
}
//Funciones que nos permiten comunicarnos con los canales virtuales de cayenne
CAYENNE_IN(1)
{ 
   int canalLed = getValue.asInt();
   digitalWrite(led, canalLed );
}

CAYENNE_IN(2)
{ 
   int canalVentilador = getValue.asInt();
   digitalWrite(ventilador, canalVentilador);
}
