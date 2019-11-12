#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads1115(0x48); //construct an ads1115 at address 0x48

void setup() 
{
  Serial.begin(9600);
  Serial.println("Inicializando...");
  ads1115.begin(); //Initialize ads1115
  Serial.println("Ajustando la ganancia...");
  ads1115.setGain(GAIN_ONE);

}


void loop() 
{
    
//SALINIDAD
const int sinSal = 15000;  // Medimos valor sin sal
const int conSal = 30675;  // Medimos valor con sal

//HUMEDAD
const int AirValue = 30413;  // Medimos valor en seco
const int WaterValue = 19000;  // Medimos valor en agua


humedad(AirValue, WaterValue);

salinidad(sinSal, conSal);
  
}


//  ---------------------

void humedad(int AirValue, int WaterValue)
{
  
  //HUMEDAD
  int16_t adc0;
  int16_t humedad;
  adc0 = ads1115.readADC_SingleEnded(0);
  
  humedad = 100*AirValue/(AirValue-WaterValue)-adc0*100/(AirValue-WaterValue);
  
  Serial.print("AIN0: ");
  Serial.println(adc0);
  Serial.println("Humedad(%): ");
  Serial.print(humedad);
  Serial.print("%");
  Serial.println();
  Serial.println("---------");
  
  delay(10000);

//--------------------------------
}



void salinidad(int sinSal, int conSal)
{

  //SALINIDAD
  int16_t adc1;
  int16_t salinity;
  adc1 = ads1115.readADC_SingleEnded(1);

  salinity = 100*sinSal/(sinSal-conSal)-adc1*100/(sinSal-conSal);

  Serial.print("AIN1: ");
  Serial.println(adc1);
  Serial.println("Salinidad(%): ");
  Serial.print(salinity);
  Serial.print("%");
  Serial.println();
  Serial.println("---------");

  delay(10000);  

//--------------------------------
}
