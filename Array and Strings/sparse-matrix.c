#include <stdio.h>
#include <stdlib.h>

int **initialize_matrix(size_t rows, size_t cols) {
    int **mat = (int **)malloc(rows * sizeof(int));
    for(int i=0; i<rows; i++)
        mat[i] = (int *)malloc(cols * sizeof(int));
    return mat;
}

void input_elements(int **arr, size_t rows, size_t cols) {
    for(size_t i=0; i<rows; i++)
        for(size_t j=0; j<cols; j++)
            scanf("%d", &arr[i][j]);
}

void print_matrix(int **arr, size_t rows, size_t cols) {
    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < cols; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

unsigned int count_non_zero_elements(int **arr, size_t rows, size_t cols) {
    unsigned int count = 0;
    for(size_t i=0; i<rows; i++) 
        for(size_t j=0; j<cols; j++)
            if(arr[i][j] != 0)
                count++;
    return count;
}

int **sparse_matrix(int **arr, size_t rows, size_t cols) {
    unsigned int non_zero_ele = count_non_zero_elements(arr, rows, cols);
    int **mat = initialize_matrix(3, non_zero_ele);
    
    size_t idx = 0;

    for(size_t i=0; i<rows; i++)
        for(size_t j=0; j<cols; j++)
            if(arr[i][j] != 0) {
                mat[0][idx] = i;
                mat[1][idx] = j;
                mat[2][idx++] = arr[i][j]; 
            }
    
    return mat;
}

int main() {
    size_t rows, cols;
    printf("Enter rows and columns of the original matrix: ");
    scanf("%lu %lu", &rows, &cols);
    int **mat = initialize_matrix(rows, cols);

    printf("Enter elements of matrix:\n");
    input_elements(mat, rows, cols);

    printf("Original matrix:\n");
    print_matrix(mat, rows, cols);

    printf("Sparse matrix:\n");
    print_matrix(sparse_matrix(mat, rows, cols), 3, count_non_zero_elements(mat, rows, cols));

    return 0;
}