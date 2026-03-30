#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

int main() {
    int array[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Enter %d number: ", i + 1);
        scanf("%d", &array[i]);
    }

    
    for(int i = 0; i < ARRAY_SIZE / 2; i++) {
        int temp = array[i];
        array[i] = array[ARRAY_SIZE - 1 - i];
        array[ARRAY_SIZE - 1 - i] = temp;
    }
    
    printf("Reversed array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
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

    for(int i = 0; i < array_size / 2; i++) {
        int temp = ptr[i];
        ptr[i] = ptr[array_size - 1 - i];
        ptr[array_size - 1 - i] = temp;
    }

    printf("Reversed array: ");
    for (int i = 0; i < array_size; i++) {
        printf("%d ", ptr[i]);
    }

    free(ptr);
    return 0;
}