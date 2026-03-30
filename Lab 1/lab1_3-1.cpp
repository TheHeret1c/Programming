#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

int main() {
    int array[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Enter %d number: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("New static vector:\n");
    for(int i = 0; i < ARRAY_SIZE; i++) {
        array[i] *= array[i];
        printf("%d ", array[i]);
    }

    // Dynamic array
    int array_size;
    printf("\nEnter a size of array: ");
    scanf("%d", &array_size);

    int *ptr = (int*) malloc(array_size * sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed");
        return 1;
    }
    
    for (int i = 0; i < array_size; i++) {
        printf("Enter %d number: ", i + 1);
        scanf("%d", &ptr[i]);
    }

    printf("New dynamic vector:\n");
    for(int i = 0; i < array_size; i++) {
        ptr[i] *= ptr[i];
        printf("%d ", ptr[i]);
    }

    free(ptr);
    return 0;
}