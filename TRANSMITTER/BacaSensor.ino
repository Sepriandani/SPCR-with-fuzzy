void BacaSensor(){
  digitalWrite(iled, HIGH);
  delayMicroseconds(280);
  int adcvalue = analogRead(vout);
  digitalWrite(iled, LOW);

  adcvalue = ds.Filter(adcvalue);
  debu = ds.Conversion(adcvalue);

}
