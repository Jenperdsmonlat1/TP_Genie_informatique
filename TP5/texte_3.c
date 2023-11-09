#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


int main(int argc, char **argv) {

    int N;
    char *chaine = (char *)malloc(sizeof(char) * 1000);
    char character[1] = "#";

    assert(argc == 2);
    N = atoi(argv[1]);

    for (int i = 0; i < N; i++) printf("%s\n", strcat(chaine, character));

    return 0;
}