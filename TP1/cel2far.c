#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {

  float temperature_faranhnein, temperature_celsius;

  if (argc < 2) {
    
    printf("[+]: Erreur, vous devez taper, ./cel2far <temperature_celsius>\n");
    return -1;
  } else {

    temperature_celsius = atof(argv[1]);
    temperature_faranhnein = temperature_celsius * 1.8 + 32;
    printf("[+]: La température en Farenhein est: %f\n", temperature_faranhnein);
  }

  return 0;
}
