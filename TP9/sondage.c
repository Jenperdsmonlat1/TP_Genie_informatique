#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <math.h>


typedef struct personne {
    unsigned int age;
    unsigned int distanceTravail;
    char commune[20];
    unsigned int revenueAnnuel;
} personne_t;

personne_t calculerMoyenne(personne_t *personnes, int index);
personne_t calculerEcartType(personne_t *personnes, int index);
void afficherHistogramme(personne_t *personnes, int index);


int main(void) {

    int index = 0;
    char saisi[2];
    personne_t *personne = (personne_t *)malloc(sizeof(personne_t) * 50);

    while (true) {
        
        printf("Quel âge avez-vous ? ");
        scanf("%d", &personne[index].age);
        assert(personne[index].age < 80);

        printf("A quelle distance en km de votre lieu de travail habitez-vous ? ");
        scanf("%d", &personne[index].distanceTravail);
        assert(personne[index].distanceTravail < 50);

        printf("Dans quelle commune habitez-vous ? ");
        scanf("%s", personne[index].commune);

        printf("Quel est votre revenue annuel (en €) ? ");
        scanf("%d", &personne[index].revenueAnnuel);
        index++;

        printf("Une autre personne ? (O/N): ");
        scanf("%s", saisi);

        if (strcmp(saisi, "N") == 0) break;
        else continue;
    }

    printf("Âge   Distance (km)   Commune   Revenue (€)\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < index; i++) printf("%d    %d              %s        %d\n", personne[i].age, personne[i].distanceTravail, personne[i].commune, personne[i].revenueAnnuel);

    printf("[+]: Histogramme:\n");
    afficherHistogramme(personne, index);

    return 0;
}

personne_t calculerMoyenne(personne_t *personnes, int index) {

    personne_t moyennePersonnes = {0};
    for (int i = 0; i < index; i++) {

        moyennePersonnes.age += personnes[i].age;
        moyennePersonnes.distanceTravail += personnes[i].distanceTravail;
        moyennePersonnes.revenueAnnuel += personnes[i].revenueAnnuel;
    }

    moyennePersonnes.age /= index;
    moyennePersonnes.distanceTravail /= index;
    moyennePersonnes.revenueAnnuel /= index;

    return moyennePersonnes;
}

personne_t calculerEcartType(personne_t *personnes, int index) {

    personne_t ecartTypePersonnes = {0};
    int moyenneAge = 0, moyenneDistance = 0, moyenneRevenue = 0;
    
    for (int i = 0; i < index; i++) {

        moyenneAge += personnes[i].age;
        moyenneDistance += personnes[i].distanceTravail;
        moyenneRevenue += personnes[i].revenueAnnuel;
    }

    moyenneAge /= index;
    moyenneDistance /= index;
    moyenneRevenue /= index;

    for (int i = 0; i < index; i++) {

        ecartTypePersonnes.age += pow((personnes[i].age - moyenneAge), 2);
        ecartTypePersonnes.distanceTravail += pow((personnes[i].distanceTravail - moyenneDistance), 2);
        ecartTypePersonnes.revenueAnnuel += pow((personnes[i].revenueAnnuel - moyenneRevenue), 2);
    }

    ecartTypePersonnes.age = sqrt(ecartTypePersonnes.age) / index;
    ecartTypePersonnes.distanceTravail = sqrt(ecartTypePersonnes.distanceTravail) / index;
    ecartTypePersonnes.revenueAnnuel = sqrt(ecartTypePersonnes.revenueAnnuel) / index;

    return ecartTypePersonnes;
}

void afficherHistogramme(personne_t *personnes, int index) {

    int pers[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < index; i++) {

        if (personnes[i].age >= 18 && personnes[i].age <= 25) pers[0]++;
        else if (personnes[i].age >= 26 && personnes[i].age <= 40) pers[1]++;
        else if (personnes[i].age >= 41 && personnes[i].age <= 50) pers[2]++;
        else if (personnes[i].age > 50 && personnes[i].age <= 65) pers[3]++;
        else pers[4]++;
    }

    printf("%d %d %d %d\n", pers[0], pers[1], pers[2], pers[3]);

    printf("18 - 25: ");
    for (int j = 0; j < pers[0]; j++) {
        putchar('#');
    }
    putchar('\n');

    printf("26 - 40: ");
    for (int j = 0; j < pers[1]; j++) {
        putchar('#');
    }
    putchar('\n');

    printf("41 - 50: ");
    for (int j = 0; j < pers[2]; j++) {
        putchar('#');
    }
    putchar('\n');

    printf("50 - 65: ");
    for (int j = 0; j < pers[3]; j++) {
        putchar('#');
    }
    putchar('\n');

    printf("65+    : ");
    for (int j = 0; j < pers[4]; j++) {
        putchar('#');
    }
    putchar('\n');

    return;
}
