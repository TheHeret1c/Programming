#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *pa = (int*) malloc(sizeof(int));
    int *pb = (int*) malloc(sizeof(int));

    if (!pa || !pb) {
        perror("Memory allocation failed!");
        return 1;
    }

    printf("Enter a number: ");
    scanf("%d", pa);
    printf("Enter b number: ");
    scanf("%d", pb);

    printf("Before swap. Number a: %d, number b: %d\n", *pa, *pb);
    
    int temp = *pa;
    *pa = *pb;
    *pb = temp;

    printf("After swap. Number a: %d, number b: %d", *pa, *pb);

    free(pa);
    free(pb);
    
    return 0;
}