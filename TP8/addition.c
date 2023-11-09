#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>


uint8_t add8(uint8_t a, uint8_t b);

int main(int argc, char **argv) {

    uint8_t n1, n2, result;

    assert(argc == 3);

    n1 = atoi(argv[1]);
    n2 = atoi(argv[2]);
    result = add8(n1, n2);
    printf("[+]: Résultat: %d\n", result);

    return 0;
}

uint8_t add8(uint8_t a, uint8_t b) {

    uint8_t somme, retenue;
    for (int8_t i = 0; i < 8; i++) {

        retenue = ((uint8_t)pow(2, i) & a) & ((uint8_t)pow(2, i) & b);
        somme |= (((uint8_t)pow(2, i) & a) ^ ((uint8_t)pow(2, i) & b)) ^ retenue;
        printf("Somme: %d Retenue: %d\n", somme, retenue);
    }

    return somme;
}
