#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {

    char voyelles[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    char chaine[100];
    int nombre_voyelles = 0;

    printf("[+]: Saisissez une chaîne: ");
    fgets(chaine, 100, stdin);

    for (int i = 0; i < strlen(chaine); i++) {
        for (int j = 0; j < sizeof(voyelles); j++) {

            if (chaine[i] == voyelles[j]) nombre_voyelles++;
            else continue;
        }
    }

    printf("[+]: Nombre de voyelles: %d\n", nombre_voyelles);

    return 0;
}