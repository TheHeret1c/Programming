#include <stdio.h>
#include <stdlib.h>

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

    printf("Sum a+b = %d", *a + *b);

    free(a);
    free(b);

    return 0;
}