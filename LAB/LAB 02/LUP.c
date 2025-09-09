#include <stdio.h>

#define N 3   // Change size if needed

// LU decomposition without pivoting (P = I)
int LUDecomposition(double A[N][N], double L[N][N], double U[N][N]) {
    for (int i = 0; i < N; i++) {
        // Upper triangular U
        for (int k = i; k < N; k++) {
            double sum = 0.0;
            for (int j = 0; j < i; j++)
                sum += (L[i][j] * U[j][k]);
            U[i][k] = A[i][k] - sum;
        }

        // Lower triangular L
        for (int k = i; k < N; k++) {
            if (i == k)
                L[i][i] = 1.0;  // diagonal = 1
            else {
                double sum = 0.0;
                for (int j = 0; j < i; j++)
                    sum += (L[k][j] * U[j][i]);

                if (U[i][i] == 0) {
                    return -1; // Failure: zero pivot
                }

                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
    return 0;
}

// Function to print a matrix with "." instead of 0.0000
void printMatrix(double M[N][N], char name) {
    printf("\n%c matrix:\n", name);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (M[i][j] == 0.0)
                printf("    .    ");
            else
                printf("%8.4f ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double A[N][N];
    double L[N][N] = {0}, U[N][N] = {0};

    // Input A
    printf("Enter the %d x %d matrix A:\n", N, N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%lf", &A[i][j]);

    if (LUDecomposition(A, L, U) == -1) {
        printf("Zero pivot found. Cannot decompose.\n");
        return 0;
    }

    // Print L and U
    printMatrix(L, 'L');
    printMatrix(U, 'U');

    return 0;
}
