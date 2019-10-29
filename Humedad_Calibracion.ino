#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads1115(0x48); // construct an ads1115 at address 0x48
const int AirValue = 30413;  // Medimos valor en seco
const int WaterValue = 19000;  // Medimos valor en agua


void setup() {
 
  Serial.begin(9600);
  Serial.println("Inicializando...");
  ads1115.begin(); //Initialize ads1115
  Serial.println("Ajustando la ganancia...");
  ads1115.setGain(GAIN_ONE);
  
  Serial.println("Tomando medidas del canal AIN0");
  
  Serial.println("Rango del ADC: +/- 4.096V (1 bit=2mV)");
}

void loop() {
  
int16_t adc0;
int16_t humedad;
adc0 = ads1115.readADC_SingleEnded(0);
humedad = 100*AirValue/(AirValue-WaterValue)-adc0*100/(AirValue-WaterValue);

Serial.print("AIN0: ");
Serial.println(adc0);
Serial.print("HR (%): ");
Serial.print(humedad);
Serial.println("%");

delay(5000);

}
