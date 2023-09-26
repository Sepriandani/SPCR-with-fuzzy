#include "WaveshareSharpDustSensor.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int pesan[1];
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;

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

String output;
float arrayDebu[3];


void setup() {
  pinMode(iled, OUTPUT);
  digitalWrite(iled, LOW);
  Serial.begin(9600);

  radio.begin(); 
  radio.openWritingPipe(pipe);
}

void loop() {
  BacaSensor();
  FuzzyLogic();
  
  if (output.equals("Bersih")) {
    pesan[0] = 0;
  } else {
    pesan[0] = 1;
  }

  radio.write(pesan, 1);
  TampilSerial();
}
