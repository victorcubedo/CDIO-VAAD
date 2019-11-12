#include <Wire.h>
#include <Adafruit_ADS1015.h>

int outputpin = 5;
int inputpin = 1;  //Pin analógico por el que hace la lectura

int SalMax = 20593; //Medida con sal
int SalMin = 3021; //Medida sin sal

void setup() {
  Serial.begin(9600);
  pinMode(outputpin, OUTPUT); //Pin digital que suministra 5V
}

void loop() {
  int salinidad;
  salinidad = fsalinidad(); //Igualamos la función a la variable

  Serial.println(salinidad);  //Muestra el valor de salinidad

}


//------FUNCION SALINIDAD------------------------------------------//
int fsalinidad() {
  int adc1;
  int lectura;  //Aquí guardaremos la lectura de salinidad
  digitalWrite(outputpin, HIGH);  //Enciende el pin 5
  delay(100); //Se espera 100 ms
  adc1 = analogRead(inputpin); //Guarda los datos en la variable
  digitalWrite(outputpin, LOW); //Apaga el pin 5
  int salinidad;
  salinidad = 100*SalMin/(SalMin-SalMax)-adc1*100/(SalMin-SalMax); //operación para calcular la salinidad
  return salinidad;
}
