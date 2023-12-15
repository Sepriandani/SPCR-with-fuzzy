#include "WaveshareSharpDustSensor.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

// INISIASI MOTOR DRIVER
//RODA
int R_PWM1 = 13;
int L_PWM1 = 12;
int R_ENA1 = 11;
int L_ENA1 = 10;

//KAIN
int R_PWM2 = 9;
int L_PWM2 = 8;
int R_ENA2 = 7;
int L_ENA2 = 6;

// POMPA
const int pump = 2;

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
#define ECHO_PIN2 3
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
float Keluaran, Kecepatan;

String outputFuzzy;
float arrayDebu[3];

int state = 0;

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
  digitalWrite(pump, HIGH);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(5, 1);
  lcd.print("Welcome to");
  lcd.setCursor(8, 2);
  lcd.print("SPCR");
  delay(3000);
}

void loop() {
  BacaSensor();
  FuzzyLogic();
  TampilSerial();
  TampilLCD();

  Kecepatan = map(Keluaran, 0, 100, 0, 255);
  Serial.println("Kecepatan kain: " + String(Kecepatan));

  if (outputFuzzy == "Bersih") {
    stop_();
    berhenti_putar();
    pump_off();
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pompa: ON");
    pump_on();
    lcd.setCursor(0, 1);
    lcd.print("Kain: ON");
    lcd.setCursor(0, 2);
    lcd.print("Kecepatan: " + String(Kecepatan));
    putar(Kecepatan);

    if (jarak1 < 10 && jarak2 > 10) {
      maju();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Roda: Maju");
      bool cekJarak2 = true;
      while (cekJarak2) {
        bacaJarak2();
        lcd.setCursor(0, 1);
        lcd.print("jarak2:" + String(jarak2));
        if (jarak2 < 10) {
          stop_();
          cekJarak2 = false;
        }
        delay(1000);
      }
    }

    if (jarak2 < 10 && jarak1 > 10) {
      mundur();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Roda: Mundur");
      bool cekJarak1 = true;
      while (cekJarak1) {
        bacaJarak1();
        lcd.setCursor(0, 1);
        lcd.print("jarak1:" + String(jarak1));
        if (jarak1 < 10) {
          stop_();
          cekJarak1 = false;
        }
        delay(1000);
      }
    }
  }
}
