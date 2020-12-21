//#include <funciones.ino>;
#include <Adafruit_ADS1015.h>
#include <Wire.h>
Adafruit_ADS1115 ads1115(0x48);


void setup() {
  //inicializamos
  Serial.begin(9600);
  //inicializamo mi ADS1115
  ads1115.begin();
  //ajustamos la ganancia
  ads1115.setGain(GAIN_ONE);
  //asigno a la salida a mi pin y mis leds

}

void loop() {
  //llamamos a la funcion de humedad
  float humedad = humedadFuncion(ads1115, 0);
  //llamamos a la funcion de salinidad
  float salinidad = salinidadFuncion(ads1115, 3);
  //llamamos a la funcion de temperatura
  float temperatura = temperaturaFuncion(ads1115, 1);
  //llamamos a la funcion de
  float luminosidad = luminosidadFuncion(ads1115, 2);



  //IMPRIMO MIS VALORES POR PANTALLA DE HUMEDAD, SALINIDAD, TEMPERATURA y LUMINOSIDAD
  Serial.print("HUMEDAD : ");
  Serial.println(humedad);
  delay(2000);

  Serial.print("SALINIDAD: ");
  Serial.println(salinidad);
  delay(2000);

  Serial.print("TEMPERATURA : ");
  Serial.print(temperatura);
  Serial.println("C");
  delay(2000);

  Serial.print("LUMINOSIDAD : ");
  Serial.println(luminosidad);
  delay(2000);


}
