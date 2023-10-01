#include "WaveshareSharpDustSensor.h"
// #include <LiquidCrystal_I2C.h>

// LiquidCrystal_I2C lcd(0x27, 20, 4);

// INISIASI MOTOR DRIVER
int R_PWM1 = 13;
int L_PWM1 = 12;
int R_ENA1 = 11;
int L_ENA1 = 10;

int R_PWM2 = 9;
int L_PWM2 = 8;
int R_ENA2 = 7;
int L_ENA2 = 6;

// POMPA
#define pump A5

//INISIASI SENSOR DEBU
const int vout = A0;
float debu;
WaveshareSharpDustSensor ds;

//INISIASI SENSOR JARAK 1
#define TRIG_PIN1 A1
#define ECHO_PIN1 A2
float jarak1 = 0;

//INISIASI SENSOR JARAK 2
#define TRIG_PIN2 A3
#define ECHO_PIN2 A4
float jarak2 = 0;

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
  Serial.begin(9600);

  pinMode(R_PWM1, OUTPUT);
  pinMode(L_PWM1, OUTPUT);
  pinMode(R_ENA1, OUTPUT);
  pinMode(L_ENA1, OUTPUT);

  pinMode(R_PWM2, OUTPUT);
  pinMode(L_PWM2, OUTPUT);
  pinMode(R_ENA2, OUTPUT);
  pinMode(L_ENA2, OUTPUT);

  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);

  pinMode(pump, OUTPUT);

  // lcd.init();
  // lcd.backlight();
  // lcd.setCursor(3, 1);
  // lcd.print("Hipostarine.co");
  // lcd.setCursor(1, 2);
  // lcd.print("For Better Farming");
}

void loop() {
  BacaSensor();
  FuzzyLogic();

  if (output.equals("Bersih")) {
    stop_();
    Serial.println("roda berhenti");
    berhenti_putar();
    Serial.println("kain berhenti");
    digitalWrite(pump, HIGH);
    Serial.println("pump berhenti");
    Serial.println("\n");
  } else {
    digitalWrite(pump, LOW);  //pump aktif
    Serial.println("pump aktif");
    delay(5000);

    putar(255);
    Serial.println("kain aktif");
    delay(5000);

    maju(255);
    Serial.println("Roda aktif");
    delay(5000);
  }

  TampilSerial();
  delay(1000);
}
