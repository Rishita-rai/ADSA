LU Decomposition Solver (with Partial Pivoting)


This program performs LU decomposition with partial pivoting (LUP) to solve a system of linear equations:

    Ax = b

where:
- A is an n x n matrix,
- x is the solution vector,
- b is the constants vector.


How it works

1. The program factorizes A into L (lower triangular), U (upper triangular), and a permutation matrix P:
       PA = LU

2. It then solves:
   - Forward substitution: Ly = Pb
   - Backward substitution: Ux = y

3. The final result is the solution vector x.


How to Compile and Run

1. Save the provided C code into a file, e.g. lup_solver.c

2. Compile:
       gcc lup_solver.c -o lup_solver -lm

3. Run:
       ./lup_solver

-----------------------------------------------
Input Format
-----------------------------------------------
- First, enter the matrix A row by row.
- Then, enter the vector b.

Example input for a 3x3 system:
    Enter the elements of matrix A (3x3):
    A[0][0] = 2
    A[0][1] = -1
    A[0][2] = -2
    A[1][0] = -4
    A[1][1] = 6
    A[1][2] = 3
    A[2][0] = -4
    A[2][1] = -2
    A[2][2] = 8
    Enter the elements of vector b (3 values):
    b[0] = -2
    b[1] = 9
    b[2] = -5

-----------------------------------------------
Output Format
-----------------------------------------------
The program prints the solution vector x:

Example output:
    Solution x:
    x[0] = 1.000000
    x[1] = 2.000000
    x[2] = -1.000000


Time Complexity

- LUP decomposition: O(n^3)
- Forward + Back substitution: O(n^2)
- Total: O(n^3)

This is efficient for medium-size systems (up to a few thousand unknowns).


Notes
- The program currently uses #define N 3. To solve for a different size, change N in the code or extend to dynamic allocation.
- Handles partial pivoting (row swaps) for numerical stability.
- Prints solution with 6 decimal precision.
