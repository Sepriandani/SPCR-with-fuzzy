void FuzzyLogic(){
  fuzzifikasi(debu);
  defuzzifikasi();
  rules();
}

//=====================Fungsi Keanggotaan================================//
float uSedikit(float debu){
  if (debu <=a ){sedikit =1;}
  else if (debu >=a && debu <=b){sedikit=(b-debu)/(b-a);}
  else if (debu >= b){sedikit =0;}
  return sedikit;
}

float uSedang(float debu){
  if (debu == b ){sedang =1;}
  else if (debu <= a || debu >= c){sedang = 0;}
  else if (debu >=a && debu <=b){sedang=(debu-a)/(b-a);}
  else if (debu >=b && debu <=c){sedang=(c-debu)/(c-b);}
  return sedang;
}

float uBanyak(float debu){
  if (debu >= c ){banyak =1;}
  else if (debu <= b){banyak = 0;}
  else if (debu >=b && debu <=c){banyak=(debu-b)/(c-b);}
  return banyak;
}

//=====================Fuzzifikasi================================//
void fuzzifikasi(float debu){
  uSedikit(debu);
  uSedang(debu);
  uBanyak(debu);
}

//=====================Rules================================//
void rules(){
  if(kondisiDebu == sedikit){
    output = "Bersih";
  }
  else if (kondisiDebu == sedang){
    output = "Sedang";
  }
  else if (kondisiDebu == banyak){
    output = "Kotor";
  }
}

//=====================Defuzzifikasi================================//
void defuzzifikasi(){
  arrayDebu[3] = {};

  for(int i = 0; i < 3; i++){
    float data_uDebu[3] = {sedikit, sedang, banyak};
    arrayDebu[i] = data_uDebu[i];

    kondisiDebu = max(arrayDebu[i], kondisiDebu);
  }
}
