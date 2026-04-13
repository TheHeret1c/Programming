#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int array_size;
    
    printf("Enter a size of array: ");
    scanf("%d", &array_size);

    int *array = (int*) malloc(array_size * sizeof(int));

    if (array == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    for (int i = 0; i < array_size; i++) {
        printf("Enter %d number: ", i + 1);
        scanf("%d", array + i);
    }

    int *ptr = array + array_size - 1;

    printf("Elements of array in reverse: ");
    // for (int i = array_size - 1; i >= 0; i--) {
    //     printf("%d ", *(array + i));
    // }
    while(ptr >= array) {
        printf("%d ", *ptr);
        ptr--;
    }

    free(array);

    return 0;
}