void TampilSerial(){
  Serial.print("Debu: ");
  Serial.print(debu);
  Serial.print(" ug/m3\n");
  String derajatKeanggotaanDebu ="Derajat Keanggotaan Debu = Sedikit: " + String(sedikit) + "  Sedang: " + String(sedang) + "  Banyak: " + String(banyak);
  Serial.println(derajatKeanggotaanDebu);
  Serial.println("Tingkat Kotoran Panel: " + output);
  Serial.println("Jarak 1: " + String(jarak1));
  Serial.println("Jarak 2: " + String(jarak2));
}
