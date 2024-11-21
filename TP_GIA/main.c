#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include "structures.h"


#define CODE_DISPO 0xD041


struct stat file_stat;
char *contenu;
uint16_t offset = 1;

uint8_t lireCreneaux(FILE *fic, creneau_t tab_creneaux[16]);
participant_t *listerDisponibilites(FILE *fic, long position, size_t *nb_participants);
void decoderDisponibilites(uint16_t codeDispo, char tabDispo[16]);
void afficherDisponibilites(size_t n1, creneau_t tab_creneaux[], size_t n2, participant_t tab_participants[]);
void enregistrerDisponibilite(FILE *fic, size_t n, creneau_t tab_creneaux[n]);
void afficherEnteteDisponibilites(size_t n, creneau_t tab_creneaux[n]);


int main(void) {

    FILE *fichier;
    creneau_t creneaux[16];

    fichier = fopen("Reunion.dat", "r");
    if (fichier == NULL) return -1;
    
    uint8_t nombre = lireCreneaux(fichier, creneaux);
    afficherEnteteDisponibilites(nombre, creneaux);

    fclose(fichier);
    return 0;
}

uint8_t lireCreneaux(FILE *fic, creneau_t tab_creneaux[16]) {

    fseek(fic, 0, SEEK_SET);

    uint8_t creneaux_nombre;
    fread(&creneaux_nombre, sizeof(uint8_t), 1, fic);
    fread(tab_creneaux, sizeof(creneau_t), creneaux_nombre, fic);

    return creneaux_nombre;
}

participant_t *listerDisponibilites(FILE *fic, long position, size_t *nb_participants) {

    char disponibilite[16];
    decoderDisponibilites(CODE_DISPO, disponibilite);

    for (uint16_t i = 15; i != 0; i--) {
        printf("%d ", disponibilite[i]);
    }
}

void afficherDisponibilites(size_t n1, creneau_t tab_creneaux[], size_t n2, participant_t tab_participants[]) {
}

void enregistrerDisponibilite(FILE *fic, size_t n, creneau_t tab_creneaux[n]) {}

void afficherEnteteDisponibilites(size_t n, creneau_t tab_creneaux[n]) {

    size_t i;
    printf("\n\t");
    for (i=0 ; i<n ; i++) printf("\t%.8s", tab_creneaux[i].jour);

    printf("\n\t");
    for (i=0 ; i<n ; i++) printf("\t%.8s", tab_creneaux[i].date);
    
    printf("\n\t");
    for (i=0 ; i<n ; i++) printf("\t%.8s", tab_creneaux[i].horaire);
    
    putchar('\n');
}

void decoderDisponibilites(uint16_t codeDispo, char tabDispo[16]) {

    for (uint8_t i = 0; i < 16; i++) tabDispo[i] = ((codeDispo & (1 << 15 - i))) / (1 << 15 - i);
}
