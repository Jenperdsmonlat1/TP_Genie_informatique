#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "outils.h"


int main(int argc, char **argv) {

    int64_t vec[10];

    initialiser(10, vec, MONOTONE_CR);
    afficherVecteur(10, vec);

    if (verifier(10, vec)) return -1;
    else return 0;
}
