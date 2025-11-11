Strassen’s Matrix Multiplication

This program implements **Strassen’s Algorithm** for fast matrix multiplication.  
It recursively divides matrices into submatrices and uses Strassen’s formula to reduce the number of multiplications.

---

How to Compile and Run

1. Save the code in a file, e.g., `strassen.c`.
2. Open a terminal and navigate to the directory containing `strassen.c`.
3. Compile the code using:

   ```bash
   gcc strassen.c -o strassen
   ```

4. Run the program:

   ```bash
   ./strassen
   ```

---

Input Format

- Enter the **size of the matrix (n)**, where `n` must be a **power of 2** (e.g., 2, 4, 8, …).  
- Enter elements of **Matrix A** (n × n).  
- Enter elements of **Matrix B** (n × n).  

Example input:

```
Enter matrix size (power of 2): 2
Enter elements of matrix A:
1 2
3 4
Enter elements of matrix B:
5 6
7 8
```

---
Output Format

The program prints:  
- The input matrices `A` and `B`.  
- The resulting product matrix `C = A * B`.  

Example output:

```
Matrix A:
1 2
3 4

Matrix B:
5 6
7 8

Resultant matrix (A * B):
19 22
43 50
```

---

Time Complexity

- Strassen’s Algorithm reduces the number of multiplications from **O(n^3)** to approximately **O(n^2.81)**.  
- For very large matrices, this is faster than the standard matrix multiplication algorithm.  
- However, due to recursion overhead, for small matrices the naive approach can be faster.

---

Notes

- The program currently only works when `n` is a **power of 2**.  
- If your matrix size is not a power of 2, you can pad it with zeros.  
- No memory deallocation (`free`) is implemented, so it may lead to memory leaks for large inputs.

---

Future Improvements

- Add support for arbitrary `n` (not just powers of 2).  
- Implement memory cleanup to prevent leaks.  
- Optimize recursion cutoff by switching to standard multiplication for small matrices.
