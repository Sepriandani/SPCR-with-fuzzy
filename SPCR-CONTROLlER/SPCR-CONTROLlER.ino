#include "WaveshareSharpDustSensor.h"

const int iled = 4;
const int vout = 0;

int   adcvalue;

WaveshareSharpDustSensor ds;

void setup() {
  pinMode(iled, OUTPUT);
  digitalWrite(iled, LOW);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(iled, HIGH);
  delayMicroseconds(280);
  adcvalue = analogRead(vout);
  digitalWrite(iled, LOW);

  adcvalue = ds.Filter(adcvalue);

  float density = ds.Conversion(adcvalue);

  Serial.print("The current dust concentration is: ");
  Serial.print(density);
  Serial.print(" ug/m3\n");

  delay(1000);

}
