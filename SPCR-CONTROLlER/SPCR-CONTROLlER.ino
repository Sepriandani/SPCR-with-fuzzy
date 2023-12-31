#include "WaveshareSharpDustSensor.h"

//INISIASI SENSOR
const int iled = 4;
const int vout = 0;
float debu;
WaveshareSharpDustSensor ds;

//FUZZY
//============Tingkat Partikel Debu=============//
//Titik-titik kurva
const int a = 50;
const int b = 100;
const int c = 150;
//Variabel fuzzy
float kondisiDebu;
float sedikit, sedang, banyak;

//============Tingkat Kotoran Panel=============//
//Titik-titik kurva
int x = 30;
int y = 50;
int z = 70;
//Variabel fuzzy
float kondisiPanel;
float bersih, normal, kotor;

String output;
float arrayDebu[3];


void setup() {
  pinMode(iled, OUTPUT);
  digitalWrite(iled, LOW);
  Serial.begin(9600);
}

void loop() {
  BacaSensor();
  fuzzifikasi(debu);
  defuzzifikasi();
  rules();
  TampilSerial();
  
  delay(1000);

}
