#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int array_size;
    int sum = 0;

    printf("Enter a size of array (1 <= n <= 1000): ");
    scanf("%d", &array_size);

    if (array_size < 1 || array_size > 1000) {
        printf("Incorrect array size!");
        return 1;
    }

    int *array = (int*) malloc(array_size * sizeof(int));

    if (!array) {
        perror("Memory allocation failed!");
        return 1;
    }

    for (int i = 0; i < array_size; i++) {
        printf("Enter element #%d: ", i + 1);
        scanf("%d", array + i);
        sum += *(array + i);
    }

    printf("Sum elements: %d", sum);

    free(array);
    
    return 0;
}