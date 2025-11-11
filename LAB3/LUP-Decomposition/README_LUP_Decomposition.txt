LUP Decomposition

This program performs **LUP decomposition** of a 3x3 matrix using partial pivoting.
It decomposes a given matrix `A` into three matrices: **L (Lower triangular)**, **U (Upper triangular)**, and **P (Permutation matrix)**, such that:

    P * A = L * U

---

How to Compile and Run

1. Save the code in a file, e.g., `lup.c`.
2. Open a terminal and navigate to the directory containing `lup.c`.
3. Compile the code using:

   ```bash
   gcc lup.c -o lup -lm
   ```

   (The `-lm` flag links the math library.)

4. Run the program:

   ```bash
   ./lup
   ```

---

Input Format

The program asks you to enter a **3x3 matrix**.  
Enter the numbers row by row.

Example input:

```
2 0 2
1 1 1
3 2 3
```

---

Output Format

The program prints the **L**, **U**, and **P** matrices.

Example output:

```
L matrix:
   1.0000    0.0000    0.0000
   0.3333    1.0000    0.0000
   0.6667   -0.5000    1.0000

U matrix:
   3.0000    2.0000    3.0000
   0.0000    0.3333    0.0000
   0.0000    0.0000    1.0000

P matrix:
   0.0000    0.0000    1.0000
   1.0000    0.0000    0.0000
   0.0000    1.0000    0.0000
```

---

Time Complexity

- The LUP decomposition uses nested loops similar to Gaussian elimination.
- **Time Complexity:** `O(n^3)` (for an n×n matrix).
- Since we are using a **3x3** matrix (`n = 3`), the runtime is very small.

---
Notes

- The program works for any **non-singular 3x3 matrix**.
- If the matrix is singular (determinant = 0), the program will display:

  ```
  Matrix is singular!
  ```

---

Future Improvements

- Extend the code to handle **NxN matrices** by making `N` dynamic.
- Add support for solving linear systems using the decomposition.
