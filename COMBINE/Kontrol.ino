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