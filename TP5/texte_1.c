#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main(int argc, char **argv) {

    int N;

    assert(argc == 2);
    N = atoi(argv[1]);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) putchar('#');
        putchar('\n');
    }

    return 0;
}