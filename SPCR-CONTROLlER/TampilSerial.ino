void TampilSerial(){
  Serial.print("The current dust concentration is: ");
  Serial.print(debu);
  Serial.print(" ug/m3\n");
  String derajatKeanggotaanDebu ="Derajat Keanggotaan Debu = Sedikit: " + String(sedikit) + "  Sedang: " + String(sedang) + "  Banyak: " + String(banyak);
  Serial.println(derajatKeanggotaanDebu);
  Serial.println("Tingkat Kotoran Panel: " + output);
}
