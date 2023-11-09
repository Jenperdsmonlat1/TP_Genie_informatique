#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>


#define TOLL 0.000001


float fun(float x);

int main(int argc, char **argv) {

    float x0, x1, x, y0, y1, y;

    assert(argc == 3);

    x0 = atof(argv[1]);
    x1 = atof(argv[2]);

    y0 = fun(x0);
    y1 = fun(x1);

    do {

        x = x1 - y1 * ((x1 - x0) / (y1 - y0));
        y = fun(x);
        x0 = x1;
        x1 = x;
        y0 = y1;
        y1 = y;
    } while (fabs(y1) > TOLL);


    printf("[+]: X value: %f\n", x);

    return 0;
}

float fun(float x) {

    return x + exp(x);
}