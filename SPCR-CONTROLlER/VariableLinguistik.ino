//=====================Tingkat Partikel Debu================================//

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

//=====================Tingkat Kotoran Panel================================//

float uBersih(float panel){
  if (panel <=x ){bersih =1;}
  else if (panel >= y){bersih =0;}
  else if (panel >=x && panel <=y){bersih=(y-panel)/x;}
  return bersih;
}
float uNormal(float panel){
  if (panel == y ){normal =1;}
  else if (panel <= x || panel >= z){normal =0;}
  else if (panel >=x && panel <=y){normal=(panel-x)/x;}
  else if (panel >=y && panel <=z){normal=(z-panel)/x;}
  return normal;
}
float uKotor(float panel){
  if (panel >= z ){kotor =1;}
  else if (panel <= y){kotor = 0;}
  else if (panel >=y && panel <=z){kotor=(panel-y)/x;}
  return kotor;
}
