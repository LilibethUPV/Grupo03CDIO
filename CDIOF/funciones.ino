

//creamos mi funcion de humedad
float humedadFuncion(Adafruit_ADS1115 ads1115, int pinH) {

  const int AirValue =   23974;
  const int WaterValue = 17914 ;

  //leo mi ADS1115 asigno al pin donde tengo conectado  numero 0

  float  adch = ads1115.readADC_SingleEnded(pinH);
  //realizamos el calculo para poder calcular nuestra humedad
  float humedad = 100 * AirValue / (AirValue - WaterValue) - adch * 100 / (AirValue - WaterValue);

  //creo mi condicional para que no tengamos valores negativos
  //con los mismos valores
  if (humedad > 100) {
    humedad = 100;
    

  }
  if (humedad < 0) {
    humedad = 0 * -1;
  }
  return humedad;

}


//creamos mi funcion de salinidad

float salinidadFuncion(Adafruit_ADS1115 ads1115, int pinS) {
  const int variable_salinidad = 20160;
  const int air_salinidad = 10111;
  const int pin_power = 5;

  pinMode(pin_power, OUTPUT);

  digitalWrite(pin_power, HIGH);

  //leo mi ADS1115 asigno al pin donde tengo conectado  numero 1
  float adcS = ads1115.readADC_SingleEnded(pinS);
  //realizamos el calculo para poder calcular nuestra salinidad

  float   salinidad = 100 * air_salinidad / (air_salinidad - variable_salinidad) - adcS * 100 / (air_salinidad - variable_salinidad);

  digitalWrite(pin_power, LOW);

  if (salinidad > 100) {
    salinidad = 100;

  }

  if (salinidad < 0) {
    salinidad = 0 * -1;
  }

  return salinidad;
}


//creamos mi funcion de temperatura

float temperaturaFuncion(Adafruit_ADS1115 ads1115, int pinT) {
  // tenemos mis dos constantes b y m que hemos calculado con anterioridad
  float b = 0.788;
  float m = 0.035;
  //calculamos 2 a la 15
  float A = pow (2, 15);
  //valor maximo de V
  float Vol = 4.096;

  //leo mi ADS1115 asigno al pin donde tengo conectado  numero 3

  float  adcT = ads1115.readADC_SingleEnded(pinT);
  //realizamos el calculo para poder calcular nuestra temperatura

  float  temperatura =  ((Vol * adcT) - (((A - 1) * b))) / ((A - 1) * m);
  return temperatura;

}

int luminosidadFuncion(Adafruit_ADS1115 ads1115, int pinL) {
  int adcL = ads1115.readADC_SingleEnded(pinL);
  int luminosidad = adcL;

  if (luminosidad > 600) {
    Serial.println("LUZ ALTA");
  }
  if (luminosidad< 600 & luminosidad >200) {
    Serial.println("LUZ MEDIA");
  }
  if (luminosidad < 16) {
    Serial.println("LUZ BAJA");
  }

  return luminosidad;
}
