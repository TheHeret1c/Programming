#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

int main() {

    // Static matrix
    double matrix[ROWS][COLS];

    printf("Enter matrix:\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }

    for (int i = 0; i < ROWS; i++) {
        double avg = 0;
        for (int j = 0; j < COLS; j++) {
            avg += matrix[i][j];
        }
        avg /= COLS;
        matrix[i][0] = avg;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%5.1lf  ", matrix[i][j]);
        }
        printf("\n");
    }


    // Dynamic matrix
    // int rows, cols;
    // printf("\nEnter count rows of array: ");
    // scanf("%d", &rows);

    // printf("Enter count cols of array: ");
    // scanf("%d", &cols);

    // int **dyn_matrix = (int**) malloc(rows * sizeof(int*));

    // for (int i = 0; i < rows; i++) {
    //     dyn_matrix[i] = (int*) malloc(cols * sizeof(int));
    // }
    
    // printf("Enter matrix:\n");

    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {
    //         printf("A[%d][%d] = ", i, j);
    //         scanf("%d", &dyn_matrix[i][j]);
    //     }
    // }

    // int **t_dyn_matrix = (int**) malloc(cols * sizeof(int*));

    // for (int i = 0; i < cols; i++) {
    //     t_dyn_matrix[i] = (int*) malloc(rows * sizeof(int));
    // }

    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {
    //         t_dyn_matrix[j][i] = dyn_matrix[i][j];
    //     }
    // }
    
    // printf("Transp matrix:\n");
    // for (int i = 0; i < cols; i++) {
    //     for (int j = 0; j < rows; j++) {
    //         printf("%3d  ", t_dyn_matrix[i][j]);
    //     }
    //     printf("\n");
    // }

    // for (int i = 0; i < rows; i++) {
    //     free(dyn_matrix[i]);
    // }
    // free(dyn_matrix);

    // for (int i = 0; i < cols; i++) {
    //     free(t_dyn_matrix[i]);
    // }
    // free(t_dyn_matrix);
    return 0;
}