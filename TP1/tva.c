/*
Calcul d'une TVA en prenant en compte l'entrée de l'utilisateeur dans la ligne de commande.
Commande de compilation: make tva
*/

#include <stdio.h>
#include <stdlib.h>

#define TVA 0.2

int main(int argc, char **argv) {

    float prix, result;

    if (argc < 2) {

        printf("[+]: Erreur, vous devez saisir: ./tva <prix>\n");
        return -1;
    } else {

        prix = atof(argv[1]);
        result = (1 + TVA) * prix;
        printf("[+]: Le résultat est: %f\n", result);
    }

    return 0;
}
