/*---------------------------------------------------------------------------------------------
    AUTORES : Denis Felst - Alejandro Mirralles - Alenjandro Losa - Vitor Cubedo.
    FECHA : 11/11/2019
    En este programa hemos implementado la medida de temperatura. Cada 10 segundo muestra las medidas
  ---------------------------------------------------------------------------------------------*/
#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads1115(0x48); //construye una dirección para el ADS 0x48

void setup()
{
  Serial.begin(9600);
  Serial.println("Inicializando...");
  ads1115.begin(); //Inicia el ADS
  Serial.println("Ajustando la ganancia...");
  ads1115.setGain(GAIN_ONE); //Ajusta la ganancia

}
/*---------------------------------------------------------------------------------------------

  ---------------------------------------------------------------------------------------------*/
void loop()
{
  /*---------------------------------------------------------------------------------------------
      Constantes necesarias para las medidad.
     ---------------------------------------------------------------------------------------------*/
  //SALINIDAD
  const int sinSal = 15000;  // Medimos valor sin sal
  const int conSal = 30675;  // Medimos valor con sal

  //HUMEDAD
  const int AirValue = 30413;  // Medimos valor en seco
  const int WaterValue = 19000;  // Medimos valor en agua

  //TEMPERATURA
  const double b = 0.79;    //Constantes para la medida de temperatura
  const double m = 0.03;
  /*---------------------------------------------------------------------------------------------
       Llamada de las funciones.
   ---------------------------------------------------------------------------------------------*/

  humedad(AirValue, WaterValue);  //Llamamos a la función que mide la humedad.

  salinidad(sinSal, conSal);    //Llamamos a la función que mide la salinidad.

  temperatura(b, m);  //Llamamos a la función que mide la temperatura.

}

/*---------------------------------------------------------------------------------------------
   A continuación estan escritas las funciones.
  ---------------------------------------------------------------------------------------------*/

void humedad(int AirValue, int WaterValue){   //Lectura de humedad
 
  int16_t adc0;
  int16_t humedad;
  adc0 = ads1115.readADC_SingleEnded(0);

  humedad = 100 * AirValue / (AirValue - WaterValue) - adc0 * 100 / (AirValue - WaterValue); //Operación para medir la humedad mediante el ADS

  Serial.print("AIN0: "); 
  Serial.println(adc0);   //Valor del adc
  Serial.println("Humedad(%): ");
  Serial.print(humedad);  //Valor calculado de humedad
  Serial.print("%");
  Serial.println();
  Serial.println("---------");

  delay(10000);
}
//-------------------------------------------------------------------------------------------
void salinidad(int sinSal, int conSal){   //Lectura de salinidad
  
  int16_t adc1;
  int16_t salinity;
  adc1 = ads1115.readADC_SingleEnded(1);

  salinity = 100 * sinSal / (sinSal - conSal) - adc1 * 100 / (sinSal - conSal); //Operación para medir la salinidad mediante el ADS

  Serial.print("AIN1: ");
  Serial.println(adc1); //Valor del adc
  Serial.println("Salinidad(%): ");
  Serial.print(salinity);   //Valor calculado de salinidad
  Serial.print("%");
  Serial.println();
  Serial.println("---------");

  delay(10000);
}
//-------------------------------------------------------------------------------------------
void temperatura(double b, double m)    //Lectura de temperatura
{
  int16_t adc2 = ads1115.readADC_SingleEnded(2);
  double elevado = 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2;   //Hemos tenido proble para elevar un número y está ha siddo la solución que se nos ha ocurrido (2^15).
  double x = (adc2 / elevado) * 4.096;   //Operaciónes para medir la temperatura mediante el ADS
  double temperatura = ((x - b) / m);

  Serial.println("AIN2: ");
  Serial.println(adc2); //Valor del adc
  Serial.println("Temperatura(ºC) : ");
  Serial.print(temperatura);//Valor calculado de temperatura
  Serial.println();
  Serial.println("---------");

  delay(10000);
}
