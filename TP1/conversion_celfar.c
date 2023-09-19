#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {

  float temperature, resultat;

  if (argc < 3) {

    printf("[+]: Erreur, vous devez écrire: ./conversion_celfar <temperature> <type>\n");
    printf("[+]: Types: celsius, faranhein\n");
    return -1;
  } else {

    temperature = atof(argv[1]);
    if (strcmp(argv[2], "celsius") == 0) {

      resultat = (temperature - 32) / 1.8;
      printf("[+]: La température en Celsius est: %f\n", resultat);
    } else if (strcmp(argv[2], "faranhein") == 0) {

      resultat = temperature * 1.8 + 32;
      printf("[+]: La température en Faranhein est: %f\n", resultat);
    }
  }

  return 0;
}
