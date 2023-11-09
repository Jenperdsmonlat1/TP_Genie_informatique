#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv) {

    char mot[10] = "MOUVEMENT", buffer[10] = "---------";
    char *character = (char *)malloc(sizeof(char));
    int pos;

    printf("[+]: Saisissez un caractère: ");
    fgets(character, stdin);

    if (strpos(mot, character) != -1) {

        
    }

    free(mot);
    free(buffer);

    return 0;
}