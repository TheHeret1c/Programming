#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    printf("Enter count rows of array: ");
    scanf("%d", &rows);

    printf("Enter count cols of array: ");
    scanf("%d", &cols);

    int **dyn_matrix = (int**) malloc(rows * sizeof(int*));

    if (!dyn_matrix) {
        printf("Memory allocation failed!");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        dyn_matrix[i] = (int*) malloc(cols * sizeof(int));
        if (!dyn_matrix[i]) {
            printf("Memory allocation failed!");
            for (int k = 0; k < i; k++) {
                free(dyn_matrix[k]);
            }
            free(dyn_matrix);
            return 1;
        }
    }
    
    printf("Enter matrix:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &dyn_matrix[i][j]);
        }
    }

    
    printf("Dynamic matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d  ", dyn_matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(dyn_matrix[i]);
    }
    free(dyn_matrix);

    return 0;
}