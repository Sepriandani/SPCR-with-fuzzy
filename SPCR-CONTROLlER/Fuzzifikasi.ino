void fuzzifikasi(float debu){
  uSedikit(debu);
  uSedang(debu);
  uBanyak(debu);
}
 
void rules(){
  if(kondisiDebu == sedikit){
    output = "Bersih";
  }
  else if (kondisiDebu == sedang){
    output = "Normal";
  }
  else if (kondisiDebu == banyak){
    output = "Kotor";
  }
}
