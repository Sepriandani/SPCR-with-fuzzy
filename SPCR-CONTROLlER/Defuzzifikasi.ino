void defuzzifikasi(){
  float pembil = 0, penyeb = 0, centre_of_area = 0;
  arrayDebu[3] = {};

  for(int i = 0; i < 3; i++){
    float data_uDebu[3] = {sedikit, sedang, banyak};
    arrayDebu[i] = data_uDebu[i];

    kondisiDebu = max(arrayDebu[i], kondisiDebu);
  }
}
