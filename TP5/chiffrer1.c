#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


int main(int argc, char **argv) {

    int cle;
    char *message = (char *)malloc(sizeof(char) * 100);

    assert(argc > 2);

    cle = atoi(argv[2]);

    if (strcmp(argv[1], "-d") == 0) {
        
        printf("Déchiffrement.\n");
        message = argv[3];
        for (int i = 0; i < strlen(message); i++) message[i] -= cle;
        printf("[+]: Message déchiffré: %s\n", message);
    } else if (strcmp(argv[1], "-c") == 0) {

        printf("Chiffrement.\n");
        message = argv[3];
        for (int i = 0; i < strlen(message); i++) message[i] += cle;
        printf("[+]: Nouveau message: %s\n", message);
    } else {
        
        printf("Aucun ne correspond.\n");
        return -1;
    }

    return 0;
}