void bacaDebu(){
  delayMicroseconds(280);
  int adcvalue = analogRead(vout);

  adcvalue = ds.Filter(adcvalue);
  debu = ds.Conversion(adcvalue);
}

void bacaJarak1(){
  long duration1;

  digitalWrite(TRIG_PIN1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN1, LOW);
  duration1 = pulseIn(ECHO_PIN1, HIGH);

  jarak1 = duration1 / 58;
}

void bacaJarak2(){
  float duration2;

  digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);
  duration2 = pulseIn(ECHO_PIN2, HIGH);

  jarak2 = duration2 / 58;
}

void BacaSensor(){
  bacaDebu();
  bacaJarak1();
  bacaJarak2();
}
