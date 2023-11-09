#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define TAILL_MAX 60
#define COTE 50

int main(int argc, char **argv) {

    int space;
    char *texte = (char *)malloc(sizeof(char) * 58);

    printf("[+]: Saisissez une chaîne de caractère: ");
    fgets(texte, 58, stdin);

    space = (TAILL_MAX / 2) - 2 - (strlen(texte) / 2);

    for (int i = 0; i < TAILL_MAX; i++) putchar('#');
    putchar('\n');

    putchar('#');
    for (int j = 0; j < TAILL_MAX - 2; j++) putchar(' ');
    printf("#\n");

    putchar('#');
    for (int k = 0; k < space; k++) printf(" ");
    printf("%s", texte);
    for (int k = 0; k < space; k++) printf(" ");
    printf("#\n");
    
    //for (int i = 0; i < TAILL_MAX - 2; i++) {
    //    putchar(' ');
    //}
    //printf("#\n");

    putchar('#');
    for (int j = 0; j < TAILL_MAX - 2; j++) putchar(' ');
    
    printf("#\n");

    for (int i = 0; i < TAILL_MAX; i++) putchar('#');
    
    putchar('\n');

    return 0;
}