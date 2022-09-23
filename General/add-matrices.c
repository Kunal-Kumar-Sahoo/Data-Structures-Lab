#include <stdio.h>
#include <stdlib.h>

int **initialize_matrix(size_t rows, size_t cols) {
    int **mat = (int **)malloc(rows * sizeof(int));
    for(int i=0; i<rows; i++)
        mat[i] = (int *)malloc(cols * sizeof(int));
    return mat;
}

void input_elements(int **mat, int rows, int cols) {
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            scanf("%d", &mat[i][j]);
}

void print_matrix(int **mat, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }        
}

int **add_matrices(int **mat1, int **mat2, int rows, int cols) {
    int **sum = initialize_matrix(rows, cols);
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            sum[i][j] = mat1[i][j] + mat2[i][j];
    return sum;
}

int main(void) {
    size_t rows, cols;
    printf("Enter dimensions of matrices: ");
    scanf("%u %u", &rows, &cols);

    int **mat1 = initialize_matrix(rows, cols);
    int **mat2 = initialize_matrix(rows, cols);

    printf("Enter elements of first matrix:\n");
    input_elements(mat1, rows, cols);

    printf("Enter elements of second matrix:\n");
    input_elements(mat2, rows, cols);

    printf("Sum of given matrices:\n");
    print_matrix(add_matrices(mat1, mat2, rows, cols), rows, cols);

    return 0;
}