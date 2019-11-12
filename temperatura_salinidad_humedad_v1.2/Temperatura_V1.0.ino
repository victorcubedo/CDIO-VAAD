#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads1115(0x48); //construct an ads1115 at address 0x48



void setup () {
  ads1115.begin();
  ads1115.setGain(GAIN_ONE);

  Serial.begin(9600);
}

void loop () {
  int16_t adc0;
  
  const double b = 0.79;
  const double m = 0.03;
  
  adc0 = ads1115.readADC_SingleEnded(2);

  double elevado = 2*2*2*2*2*2*2*2*2*2*2*2*2*2*2;

  double x = (adc0/elevado)*4.096;

 
  
  double funcionTemp=((x-b)/m);

  Serial.println(x);
  Serial.println(adc0);
  Serial.println(funcionTemp);
  Serial.println("-------");
  delay(7000);




}
