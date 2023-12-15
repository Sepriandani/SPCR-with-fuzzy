void TampilLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Status: " + outputFuzzy);
  lcd.setCursor(0, 1);
  lcd.print("Debu:" + String(debu));
  lcd.setCursor(0, 2);
  lcd.print("Jarak1:" + String(jarak1));
  lcd.setCursor(0, 3);
  lcd.print("jarak2:" + String(jarak2));
}