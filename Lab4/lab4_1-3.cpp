#include <stdio.h>
#include <stdlib.h>

double** allocate_matrix(int rows, int cols) {
    double **matrix = (double**)malloc(rows * sizeof(double*));
    if (matrix == NULL) {
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
        if (matrix[i] == NULL) {
            for (int k = 0; k < i; k++) {
                free(matrix[k]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

void free_matrix(double **matrix, int rows) {
    if (matrix == NULL) return;
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void fill_matrix(double **matrix, int rows, int cols) {
    printf("Enter matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void print_matrix(double **matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%8.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("Enter count rows of array: ");
    scanf("%d", &rows);
    printf("Enter count cols of array: ");
    scanf("%d", &cols);

    double **matrix = allocate_matrix(rows, cols);
    if (matrix == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    fill_matrix(matrix, rows, cols);

    print_matrix(matrix, rows, cols);

    free_matrix(matrix, rows);

    return 0;
}