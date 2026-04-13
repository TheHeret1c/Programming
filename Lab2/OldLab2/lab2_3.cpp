#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int *a = (int*) malloc(sizeof(int));
    int *b = (int*) malloc(sizeof(int));

    if (a == NULL || b == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Enter a number: ");
    scanf("%d", a);

    printf("Enter b number: ");
    scanf("%d", b);

    if (*a > *b) {
        printf("Max = %d\n", *a);
    } else {
        printf("Max = %d\n", *b);
    }

    double max = fmax((double) *a, (double) *b);
    printf("Max = %.0lf", max);

    free(a);
    free(b);

    return 0;
}