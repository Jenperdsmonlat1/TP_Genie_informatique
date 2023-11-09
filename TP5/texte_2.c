#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main(int argc, char **argv) {

    int N;
    
    assert(argc == 2);
    N = atoi(argv[1]);

    for (int i = 0; i < N; i++) putchar('#');
    putchar('\n');

    for (int i = 0; i < N - 2; i++) {
        
        putchar('#');
        for (int j = 0; j < N - 2; j++) {
            putchar(' ');
        }
        printf("#\n");
    }

    for (int i = 0; i < N; i++) putchar('#');
    printf("\n");

    return 0;
}