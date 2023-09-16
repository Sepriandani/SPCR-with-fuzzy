//=====================Tingkat Partikel Debu================================//
int a = 50;
int b = 100;
int c = 150;

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
int x = 30;
int y = 50;
int z = 70;

float uBersih(float panel){
  if (panel <=x ){bersih =1;}
  else if (panel >= y){bersih =0;}
  else if (panel >=x && panel <=y){bersih=(y-panel)/x;}
  return bersih;
}
float uSedang(float panel){
  if (panel == y ){sedang =1;}
  else if (panel <= x || panel >= 70){sedang =0;}
  else if (panel >=x && panel <=y){sedang=(panel-x)/x;}
  else if (panel >=y && panel <=z){sedang=(z-panel)/x;}
  return sedang;
}
float uKotor(float panel){
  if (panel >= z ){kotor =1;}
  else if (panel <= y){kotor = 0;}
  else if (panel >=y && panel <=z){kotor=(panel-y)/x;}
  return kotor;
}
