#include <stdio.h>
#include <stdlib.h>

#define N 3   // Change this size as needed

// LUP Decomposition with partial pivoting
int LUPDecomposition(double A[N][N], double L[N][N], double U[N][N], double P[N][N]) {
    int i, j, k, pivot;
    double maxA, absA, temp;
    int row_swap[N]; // To track permutation

    // Initialize permutation matrix P as identity
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            P[i][j] = (i == j) ? 1.0 : 0.0;
    }

    for (k = 0; k < N; k++) {
        // Pivoting: find row with max element in column k
        pivot = k;
        maxA = 0.0;
        for (i = k; i < N; i++) {
            absA = (A[i][k] > 0) ? A[i][k] : -A[i][k];
            if (absA > maxA) {
                maxA = absA;
                pivot = i;
            }
        }

        if (maxA == 0) return -1; // Singular matrix

        // Swap rows in A
        if (pivot != k) {
            for (j = 0; j < N; j++) {
                temp = A[k][j];
                A[k][j] = A[pivot][j];
                A[pivot][j] = temp;

                temp = P[k][j];
                P[k][j] = P[pivot][j];
                P[pivot][j] = temp;
            }
        }

        // Gaussian elimination
        for (i = k + 1; i < N; i++) {
            A[i][k] /= A[k][k];
            for (j = k + 1; j < N; j++) {
                A[i][j] -= A[i][k] * A[k][j];
            }
        }
    }

    // Extract L and U
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i > j) {
                L[i][j] = A[i][j];
                U[i][j] = 0.0;
            } else if (i == j) {
                L[i][j] = 1.0;
                U[i][j] = A[i][j];
            } else {
                L[i][j] = 0.0;
                U[i][j] = A[i][j];
            }
        }
    }
    return 0;
}

// Forward substitution: L*y = Pb
void forwardSubstitution(double L[N][N], double b[N], double y[N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        y[i] = b[i];
        for (j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
    }
}

// Backward substitution: U*x = y
void backwardSubstitution(double U[N][N], double y[N], double x[N]) {
    int i, j;
    for (i = N - 1; i >= 0; i--) {
        x[i] = y[i];
        for (j = i + 1; j < N; j++) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
}

// Solve Ax = b using LUP
void LUPSolve(double L[N][N], double U[N][N], double P[N][N], double b[N], double x[N]) {
    double Pb[N], y[N];
    int i, j;

    // Compute Pb
    for (i = 0; i < N; i++) {
        Pb[i] = 0.0;
        for (j = 0; j < N; j++) {
            Pb[i] += P[i][j] * b[j];
        }
    }

    forwardSubstitution(L, Pb, y);
    backwardSubstitution(U, y, x);
}

int main() {
    double A[N][N], b[N];
    double L[N][N], U[N][N], P[N][N], x[N];
    int i, j;

    // Input matrix A
    printf("Enter the %d x %d matrix A:\n", N, N);
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%lf", &A[i][j]);

    // Input vector b
    printf("Enter the vector b of size %d:\n", N);
    for (i = 0; i < N; i++)
        scanf("%lf", &b[i]);

    if (LUPDecomposition(A, L, U, P) == -1) {
        printf("Matrix is singular, cannot decompose.\n");
        return 0;
    }

    // Print L
    printf("\nL matrix:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%8.4f ", L[i][j]);
        printf("\n");
    }

    // Print U
    printf("\nU matrix:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%8.4f ", U[i][j]);
        printf("\n");
    }

    // Print P
    printf("\nPermutation matrix P:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%8.4f ", P[i][j]);
        printf("\n");
    }

    // Solve Ax = b
    LUPSolve(L, U, P, b, x);

    // Print solution
    printf("\nSolution vector x:\n");
    for (i = 0; i < N; i++)
        printf("%8.4f ", x[i]);
    printf("\n");

    return 0;
}
