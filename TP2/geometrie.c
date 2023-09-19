#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(int argc, char **argv) {

    float result;

    if (argc < 2) {
        printf("[+]: Erreur, vous devez saisir: ./geometrie <whattodo>\n");
        printf("[-]: whattodo:\n");
        printf("[-]: surface_carre: Calculer la surface d'un carré.\n");
        printf("[-]: surface_triangle: Calculer la surface d'un triangle.\n");
        printf("[-]: surface_trapeze: Calculer la surface d'un trapèze.\n");
        printf("[-]: surface_para: Calculer la surface d'un parallélogramme.\n");
        printf("[-]: surface_triangle_heron: Calculer la surface d'un triangle avec la formule de Héron.\n");
        return -1;
    } else {

        if ((strcmp("surface_carre", argv[1]) == 0) && (argc >= 3)) {
            
            result = pow(atof(argv[2]), 2);
        } else if ((strcmp("surface_triangle", argv[1]) == 0) && (argc >= 4)) {
            
            result = (atof(argv[2]) * atof(argv[3])) / 2;
        } else if ((strcmp("surface_trapeze", argv[1]) == 0) && (argc >= 5)) {
            
            result = ((atof(argv[2]) + atof(argv[3])) * atof(argv[4])) / 2;
        } else if ((strcmp("surface_para", argv[1]) == 0) && (argc >= 4)) {

            result = (atof(argv[2]) * atof(argv[3]));
        } else if ((strcmp("surface_triangle_heron", argv[1]) == 0) && (argc >= 5)) {

            float s = (atof(argv[2]) + atof(argv[3]) + atof(argv[4])) / 2;
            result = sqrt(s * (s - atof(argv[2])) * (s - atof(argv[3])) * (s - atof(argv[4])));
        } else printf("");
    }

    printf("[+]: Le résultat est: %.2f\n", result);
    return 0;
}