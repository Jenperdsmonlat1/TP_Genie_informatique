#include <stdio.h>
#include <stdint.h>
#include "outils.h"


#define TAILLE 5000000

void triRapide(int64_t vec[TAILLE], int64_t debut, int64_t fin);
void triParInsertion(int64_t n, int64_t vec[TAILLE]);
void triParSelection(int64_t n, int64_t vec[TAILLE]);


int main(int argc, char **argv) {

    int64_t vec[TAILLE];
    printf("[+]: Initialisation.\n");
    initialiser(TAILLE, vec, ALEATOIRE);

    triRapide(vec, 0, TAILLE);
    verifier(TAILLE, vec);
}

void triParSelection(int64_t n, int64_t vec[TAILLE]) {

    int min = 0, k = 0;

    for (int i = 0; i < n; i++) {

        min = i;
        for (int j = i+1; j < n; j++) if (vec[j] < vec[min]) min = j;

        if (min > i) {

            k = vec[i];
            vec[i] = vec[min];
            vec[min] = k;
        }
    }
}

void triParInsertion(int64_t n, int64_t vec[TAILLE]) {

    int val  = 0, j = 0;
    for (int i = 0; i < n; i++) {

        val = vec[i];
        j = i;
        
        while (j > 0 && val < vec[j-1]) {

            vec[j] = vec[j-1];
            j--;
        }

        vec[j] = val;
    }
}

void triRapide(int64_t vec[TAILLE], int64_t debut, int64_t fin) {

    int64_t pivot, i, j, temp;

    if (debut < fin) {

        pivot = debut;
        i = debut;
        j = fin;

        while (i < j) {
            while (vec[i] <= vec[pivot] && i < fin) i++;
            while (vec[j] > vec[pivot]) j--;

            if (i < j) {

                temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }

        temp = vec[pivot];
        vec[pivot] = vec[j];
        vec[j] = temp;
        
        triRapide(vec, debut, j-1);
        triRapide(vec, j+1, fin);
    }
}
