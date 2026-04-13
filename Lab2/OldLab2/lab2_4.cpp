#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int array_size;
    
    printf("Enter a size of array: ");
    scanf("%d", &array_size);

    double *array = (double*) malloc(array_size * sizeof(double));

    if (array == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    for (int i = 0; i < array_size; i++) {
        printf("Enter %d number: ", i + 1);
        scanf("%lf", array + i);
    }

    printf("Elements of array: ");
    for (int i = 0; i < array_size; i++) {
        printf("%.2lf ", *(array + i));
    }

    free(array);

    return 0;
}