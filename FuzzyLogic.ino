
//=====================Fungsi Keanggotaan================================//
float uSedikit(float debu) {
  if (debu <= a) {
    sedikit = 1;
  } else if (debu >= a && debu <= b) {
    sedikit = (b - debu) / (b - a);
  } else if (debu >= b) {
    sedikit = 0;
  }
  return sedikit;
}

float uSedang(float debu) {
  if (debu == b) {
    sedang = 1;
  } else if (debu <= a || debu >= c) {
    sedang = 0;
  } else if (debu >= a && debu <= b) {
    sedang = (debu - a) / (b - a);
  } else if (debu >= b && debu <= c) {
    sedang = (c - debu) / (c - b);
  }
  return sedang;
}

float uBanyak(float debu) {
  if (debu >= c) {
    banyak = 1;
  } else if (debu <= b) {
    banyak = 0;
  } else if (debu >= b && debu <= c) {
    banyak = (debu - b) / (c - b);
  }
  return banyak;
}

//=====================Fuzzifikasi================================//
void fuzzifikasi(float debu) {
  uSedikit(debu);
  uSedang(debu);
  uBanyak(debu);
}

//=====================Rules================================//
void rules() {
  if (kondisiDebu == sedikit) {
    outputFuzzy = "Bersih";
  } else if (kondisiDebu == sedang) {
    outputFuzzy = "Sedang";
  } else if (kondisiDebu == banyak) {
    outputFuzzy = "Kotor";
  }
}

int fuzzy_set[3] = { 0, 50, 100 };

//=====================Defuzzifikasi================================//
void defuzzifikasi() {
  float pembil = 0, penyeb = 0, centre_of_area = 0;
  arrayDebu[3] = {};

  for (int i = 0; i < 3; i++) {
    float data_uDebu[3] = { sedikit, sedang, banyak };
    arrayDebu[i] = data_uDebu[i];

    kondisiDebu = max(arrayDebu[i], kondisiDebu);

    /* Metode COA (Centre Of Area)*/
    pembil += arrayDebu[i] * fuzzy_set[i];
    penyeb += arrayDebu[i];
    delay(5);
  }
  centre_of_area = pembil / penyeb;
  Keluaran = centre_of_area;
}

void FuzzyLogic() {
  fuzzifikasi(debu);
  defuzzifikasi();
  rules();
}
