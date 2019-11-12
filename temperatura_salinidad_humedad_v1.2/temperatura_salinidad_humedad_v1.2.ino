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

//TEMPERATURA
const double b = 0.79;
const double m = 0.03;


//llamadas:

  humedad(AirValue, WaterValue);

  salinidad(sinSal, conSal);

  temperatura(b, m);



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




//TEMPERATURA
void temperatura(double b, double m)
{
  int16_t adc2=ads1115.readADC_SingleEnded(2);
  double elevado = 2*2*2*2*2*2*2*2*2*2*2*2*2*2*2;
  //double elevado = pow(2,15);
  double x = (adc2/elevado)*4.096;
  double temperatura=((x-b)/m);

  Serial.println("AIN2: ");
  Serial.println(adc2);
  Serial.println("Temperatura(ºC) : ");
  Serial.print(temperatura);
  Serial.println();
  Serial.println("---------");
  
  delay(10000);
}
