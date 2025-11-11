
#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int** allocateMatrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(n * sizeof(int));
    return matrix;
}

// Function to add two matrices
void addMatrix(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void subMatrix(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Strassen’s algorithm
void strassen(int **A, int **B, int **C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    // Allocate submatrices
    int **A11 = allocateMatrix(k);
    int **A12 = allocateMatrix(k);
    int **A21 = allocateMatrix(k);
    int **A22 = allocateMatrix(k);
    int **B11 = allocateMatrix(k);
    int **B12 = allocateMatrix(k);
    int **B21 = allocateMatrix(k);
    int **B22 = allocateMatrix(k);
    int **C11 = allocateMatrix(k);
    int **C12 = allocateMatrix(k);
    int **C21 = allocateMatrix(k);
    int **C22 = allocateMatrix(k);
    int **M1 = allocateMatrix(k);
    int **M2 = allocateMatrix(k);
    int **M3 = allocateMatrix(k);
    int **M4 = allocateMatrix(k);
    int **M5 = allocateMatrix(k);
    int **M6 = allocateMatrix(k);
    int **M7 = allocateMatrix(k);
    int **temp1 = allocateMatrix(k);
    int **temp2 = allocateMatrix(k);

    // Divide matrices A and B
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // M1 = (A11 + A22) * (B11 + B22)
    addMatrix(A11, A22, temp1, k);
    addMatrix(B11, B22, temp2, k);
    strassen(temp1, temp2, M1, k);

    // M2 = (A21 + A22) * B11
    addMatrix(A21, A22, temp1, k);
    strassen(temp1, B11, M2, k);

    // M3 = A11 * (B12 - B22)
    subMatrix(B12, B22, temp2, k);
    strassen(A11, temp2, M3, k);

    // M4 = A22 * (B21 - B11)
    subMatrix(B21, B11, temp2, k);
    strassen(A22, temp2, M4, k);

    // M5 = (A11 + A12) * B22
    addMatrix(A11, A12, temp1, k);
    strassen(temp1, B22, M5, k);

    // M6 = (A21 - A11) * (B11 + B12)
    subMatrix(A21, A11, temp1, k);
    addMatrix(B11, B12, temp2, k);
    strassen(temp1, temp2, M6, k);

    // M7 = (A12 - A22) * (B21 + B22)
    subMatrix(A12, A22, temp1, k);
    addMatrix(B21, B22, temp2, k);
    strassen(temp1, temp2, M7, k);

    // C11 = M1 + M4 - M5 + M7
    addMatrix(M1, M4, temp1, k);
    subMatrix(temp1, M5, temp2, k);
    addMatrix(temp2, M7, C11, k);

    // C12 = M3 + M5
    addMatrix(M3, M5, C12, k);

    // C21 = M2 + M4
    addMatrix(M2, M4, C21, k);

    // C22 = M1 - M2 + M3 + M6
    subMatrix(M1, M2, temp1, k);
    addMatrix(temp1, M3, temp2, k);
    addMatrix(temp2, M6, C22, k);

    // Combine results into matrix C
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int **M, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter matrix size (power of 2): ");
    scanf("%d", &n);
    

    int **A = allocateMatrix(n);
    int **B = allocateMatrix(n);
    int **C = allocateMatrix(n);



    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &A[i][j]);
        }
    }
    printMatrix(A, n);

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &B[i][j]);
        }
    } 
    printMatrix(B, n);   
    strassen(A, B, C, n);

    printf("Resultant matrix (A * B):\n");
    printMatrix(C, n);

    return 0;
}
