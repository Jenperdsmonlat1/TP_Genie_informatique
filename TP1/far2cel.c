#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {

  float temperature_celsius, temperature_faranhein;

  if (argc < 2) {

    printf("[+]: Erreur, vous devez saisir: ./far2cel <temperature_faranhnein>\n");
    return -1;
  } else {

    temperature_faranhein = atof(argv[1]);
    temperature_celsius = (temperature_faranhein - 32) / 1.8;
    printf("[+]: La température en Celsius est: %f\n", temperature_celsius);
  }

  return 0;
}
