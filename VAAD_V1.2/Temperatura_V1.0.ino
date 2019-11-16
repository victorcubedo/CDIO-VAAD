#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads1115(0x48); //construct an ads1115 at address 0x48



void setup () {
  ads1115.begin();  //Encendemos el ADS
  ads1115.setGain(GAIN_ONE);  //Ajustamos la ganancia a 1

  Serial.begin(9600);  //Habilitamos la comunicación con el monitor Serial
}

void loop () {
  int16_t adc0;  //Declaramos el adc
  
  const double b = 0.79;  //Constantes
  const double m = 0.03;
  
  adc0 = ads1115.readADC_SingleEnded(2);  //La lectura recogida por el pin A2 se guarda en adc0;

  double elevado = 2*2*2*2*2*2*2*2*2*2*2*2*2*2*2;  //Esto es 2^15, teniamos problemas al poner el número 
                                                   //directamente y esta fue la solucón

  double x = (adc0/elevado)*4.096; //Operación 

  double funcionTemp=((x-b)/m);  //Operación que calcula la temperatura

  Serial.println(x);
  Serial.println(adc0);
  Serial.println(funcionTemp);
  Serial.println("-------");
  delay(7000);

}
