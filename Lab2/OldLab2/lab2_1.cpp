#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // double *p0 = (double*) malloc(sizeof(double));
    // double **p1 = (double**) malloc (sizeof(double**));
    // double ***pointer = NULL;

    double n = 2;
    double *p0 = (double*) malloc(sizeof(double));
    p0 = &n;
    double **p1 = (double**) malloc(sizeof(double*));
    **p1 = *p0;
    double ***pointer = NULL;
    ***pointer = **p1;
    
    printf("%lf, %p", ***pointer, pointer);

    free(p0);
    free(p1);
    free(pointer);

    return 0;
}