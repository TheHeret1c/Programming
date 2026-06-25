#include <stdio.h>
#include <stdlib.h>

void swap_pairs(int *arr, int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

void print_array(const int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int size = 12;

    int *array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }

    printf("Original array: ");
    print_array(array, size);

    swap_pairs(array, size);

    printf("After swap:    ");
    print_array(array, size);

    free(array);

    return 0;
}