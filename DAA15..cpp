#include <stdio.h>

#define N 4 
void add(int A[][N], int B[][N], int C[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void subtract(int A[][N], int B[][N], int C[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int A[][N], int B[][N], int C[][N], int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int newSize = size / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int P1[newSize][newSize], P2[newSize][newSize], P3[newSize][newSize], P4[newSize][newSize], P5[newSize][newSize], P6[newSize][newSize], P7[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }
    add(A11, A22, temp1);
    add(B11, B22, temp2);
    strassen(temp1, temp2, P1, newSize);

    add(A21, A22, temp1);
    strassen(temp1, B11, P2, newSize);

    subtract(B12, B22, temp1);
    strassen(A11, temp1, P3, newSize);

    subtract(B21, B11, temp1);
    strassen(A22, temp1, P4, newSize);

    add(A11, A12, temp1);
    strassen(temp1, B22, P5, newSize);

    subtract(A21, A11, temp1);
    add(B11, B12, temp2);
    strassen(temp1, temp2, P6, newSize);

    subtract(A12, A22, temp1);
    add(B21, B22, temp2);
    strassen(temp1, temp2, P7, newSize);
    add(P1, P4, temp1);
    subtract(temp1, P5, temp2);
    add(temp2, P7, C11);

    add(P3, P5, C12);

    add(P2, P4, C21);

    subtract(P1, P2, temp1);
    add(temp1, P3, temp2);
    add(temp2, P6, C22);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}
void printMatrix(int mat[][N], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[N][N] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}};
    int B[N][N] = {{17, 18, 19, 20},
                   {21, 22, 23, 24},
                   {25, 26, 27, 28},
                   {29, 30, 31, 32}};
    int C[N][N]; 
    strassen(A, B, C, N);
    printf("Matrix A:\n");
    printMatrix(A, N);
    printf("\n");
    printf("Matrix B:\n");
    printMatrix(B, N);
    printf("\n");
    printf("Resultant Matrix C (A * B):\n");
    printMatrix(C, N);
    printf("\n");

    return 0;
}
