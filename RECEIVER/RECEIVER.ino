#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int pesan[1];
int pesanSebelumnya, pesanSekarang;
RF24 radio(9, 10);
const uint64_t pipe = 0xE8E8F0F0E1LL;

int R_PWM1 = 3;
int L_PWM1 = 5;
int R_ENA1 = 1;
int L_ENA1 = 2;

int R_PWM2 = 6;
int L_PWM2 = 9;
int R_ENA2 = 4;
int L_ENA2 = 7;

#define limit A0
#define pump A1
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();

  pinMode(R_PWM1, OUTPUT);
  pinMode(L_PWM1, OUTPUT);
  pinMode(R_ENA1, OUTPUT);
  pinMode(L_ENA1, OUTPUT);

  pinMode(R_PWM2, OUTPUT);
  pinMode(L_PWM2, OUTPUT);
  pinMode(R_ENA2, OUTPUT);
  pinMode(L_ENA2, OUTPUT);

  pinMode(limit, INPUT_PULLUP);
  pinMode(pump, OUTPUT);


  Serial.println("=======================================================================");
  Serial.println("                          PERSIAPAN SISTEM                             ");
  Serial.println("=======================================================================");
  Serial.println("\n\n\n");

  Serial.println("Menunggu Perintah.....");

  delay(2000);
}

void loop() {
  if (digitalRead(limit) == LOW) {
    Serial.println("\n\n\n");
    stop_();
    Serial.println("roda berhenti");
    berhenti_putar();
    Serial.println("kain berhenti");
    digitalWrite(pump, HIGH);
    Serial.println("pump berhenti");
    Serial.println("\n\n\n");


    Serial.println("=======================================================================");
    Serial.println("                         PEMBERSIHAN SELESAI                           ");
    Serial.println("=======================================================================");
    Serial.println("\n\n\n");

    while (1) {
      if (radio.available()) {  //jika terbaca data di module
        bool selesai = false;
        while (!selesai) {
          selesai = radio.read(pesan, 1);
        }
      }

      if (digitalRead(limit) == HIGH) {
        putar(255);

        Serial.println("kain aktif kembali");
        digitalWrite(pump, LOW);
        Serial.println("pompa aktif kembali");
        delay(300);

        Serial.println("\n\n\n");
        Serial.println("=======================================================================");
        Serial.println("                          PEMBERSIHAN DIMULAI KEMBALI                             ");
        Serial.println("=======================================================================");
        Serial.println("\n\n\n");

        break;
      }
    }
  } else {
    if (radio.available()) {
      bool selesai = false;
      while (!selesai) {
        selesai = radio.read(pesan, 1);
        pesanSekarang = pesan[0];
        Serial.println(pesan[0]);
        if (pesan[0] == 1) {
          digitalWrite(pump, LOW);  //pump aktif
          Serial.println("pump aktif");
          delay(5000);

          putar(255);
          Serial.println("kain aktif");
          delay(5000);

          maju(255);
          Serial.println("Roda aktif");
          delay(5000);
        } else {
          Serial.println("\n");
          stop_();
          Serial.println("roda berhenti");
          berhenti_putar();
          Serial.println("kain berhenti");
          digitalWrite(pump, HIGH);
          Serial.println("pump berhenti");
          Serial.println("\n");
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------//
void maju(int pwm) {
  digitalWrite(R_ENA1, HIGH);
  digitalWrite(L_ENA1, HIGH);
  analogWrite(L_PWM1, pwm);
  analogWrite(R_PWM1, 0);
}
void mundur(int pwm) {
  digitalWrite(R_ENA1, HIGH);
  digitalWrite(L_ENA1, HIGH);
  analogWrite(L_PWM1, 0);
  analogWrite(R_PWM1, pwm);
}
void stop_() {
  digitalWrite(R_ENA1, HIGH);
  digitalWrite(L_ENA1, HIGH);
  analogWrite(L_PWM1, 0);
  analogWrite(R_PWM1, 0);
}
//----------------------------------------------------------------------------------//
void putar(int pwm) {
  digitalWrite(R_ENA2, HIGH);
  digitalWrite(L_ENA2, HIGH);
  analogWrite(L_PWM2, pwm);
  analogWrite(R_PWM2, 0);
}
void berhenti_putar() {
  digitalWrite(R_ENA2, HIGH);
  digitalWrite(L_ENA2, HIGH);
  analogWrite(L_PWM2, 0);
  analogWrite(R_PWM2, 0);
}
