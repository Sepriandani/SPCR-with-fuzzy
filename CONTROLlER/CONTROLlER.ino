#include "WaveshareSharpDustSensor.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

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
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  BacaSensor();
  FuzzyLogic();
  TampilSerial();
  
  char text[4]; // Adjust the size if needed for your longest message
  if (output.equals("Bersih")) {
    strcpy(text, "OFF");
  } else {
    strcpy(text, "ON");
  }
  radio.write(&text, sizeof(text));
  
  delay(1000);
}
