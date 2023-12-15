void maju() {
  digitalWrite(R_ENA1, HIGH);
  digitalWrite(L_ENA1, HIGH);
  analogWrite(L_PWM1, 255);
  analogWrite(R_PWM1, 0);
}
void mundur() {
  digitalWrite(R_ENA1, HIGH);
  digitalWrite(L_ENA1, HIGH);
  analogWrite(L_PWM1, 0);
  analogWrite(R_PWM1, 255);
}
void stop_() {
  digitalWrite(R_ENA1, HIGH);
  digitalWrite(L_ENA1, HIGH);
  analogWrite(L_PWM1, 0);
  analogWrite(R_PWM1, 0);
  Serial.println("Roda : OFF");
}
//----------------------------------------------------------------------------------//
void putar(float pwm) {
  digitalWrite(R_ENA2, HIGH);
  digitalWrite(L_ENA2, HIGH);
  analogWrite(L_PWM2, pwm);
  analogWrite(R_PWM2, 0);
  Serial.println("Kain : ON");
  delay(5000);
}
void berhenti_putar() {
  digitalWrite(R_ENA2, HIGH);
  digitalWrite(L_ENA2, HIGH);
  analogWrite(L_PWM2, 0);
  analogWrite(R_PWM2, 0);
  Serial.println("Kain : OFF");
}
//----------------------------------------------------------------------------------//
void pump_on() {
  digitalWrite(pump, LOW);
  Serial.println("Pump : ON");
  delay(5000);
}
void pump_off() {
  digitalWrite(pump, HIGH);
  Serial.println("Pump : OFF");
  Serial.println("\n");
}
