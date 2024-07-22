#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size for the matrices

// Function to multiply two matrices
void multiplyMatrices(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int res[][MAX_SIZE], int size) {
    int i, j, k;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            res[i][j] = 0;
            for (k = 0; k < size; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int size;

    printf("Enter the size of the square matrices: ");
    scanf("%d", &size);

    // Check if size exceeds maximum
    if (size > MAX_SIZE) {
        printf("Size exceeds maximum allowed size of %d\n", MAX_SIZE);
        return 1;
    }

    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], res[MAX_SIZE][MAX_SIZE];
    int i, j;

    // Initialize matrices with random values (for simplicity)
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            mat1[i][j] = rand() % 10; // Random value between 0 and 9
            mat2[i][j] = rand() % 10; // Random value between 0 and 9
        }
    }

    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();

    // Perform matrix multiplication
    multiplyMatrices(mat1, mat2, res, size);

    end_time = clock();

    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Time taken for matrix multiplication: %f seconds\n", cpu_time_used);

    return 0;
}
