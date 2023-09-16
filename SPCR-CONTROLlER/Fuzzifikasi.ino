void fuzzifikasi(float debu){
  uSedikit(debu);
  uSedang(debu);
  uBanyak(debu);
}
 
void rule(){
  if(kondisiDebu == sedikit){
    output = "bersih";
  }
  else if (kondisiDebu == sedang){
    output = "sedang";
  }
  else if (kondisiDebu == banyak){
    output = "kotor";
  }
}
