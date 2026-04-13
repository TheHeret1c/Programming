#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *pa = (int*) malloc(sizeof(int));
    int *pb = (int*) malloc(sizeof(int));

    if (!pa || !pb) {
        perror("Memory allocation failed");
        return 1;
    }

    int max;

    printf("Enter a number: ");
    scanf("%d", pa);
    printf("Enter b number: ");
    scanf("%d", pb);

    if (*pa > *pb) {
        max = *pa;
    }
    else {
        max = *pb;
    }

    printf("Max: %d", max);

    free(pa);
    free(pb);
    return 0;
}