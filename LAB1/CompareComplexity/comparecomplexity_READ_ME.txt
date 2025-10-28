Compare Complexity Program takes the input as size of array(No of Elements to be entered for plotting map)

Once the input(No of array Elements) is given, It takes array elements(n) as input, In the backend, the code computes the function values 

The Function values are plotted against n.

The graph can be used for arranging the functions in increasing order.

Function Growth Comparison in C:
This program compares the growth of different mathematical functions and arranges them in increasing order of their values for a large input size n. It also checks which functions are asymptotically equivalent (Θ-equivalent) by comparing their ratios at two different input sizes.

Features:
Implements 12 growth functions (e.g., n log n, sqrt(n), n^2, 3^n, etc.).
Sorts them in increasing order of values for a given n.
Prints the function names alongside their computed values in scientific notation.
Approximates Θ-equivalence using ratio comparisons at two test points (n1 = 10000, n2 = 1000000).

Functions Implemented:
n log n
12 sqrt(n)
1/n
n^(log2 n)
100n^2 + 6n
n^0.51
n^2 - 324
50 sqrt(n)
2n^3
3^n
2^32 n
log2 n


Notes:
The sorting is based on values at a particular n, not theoretical asymptotic classes.
Θ-equivalence checking is only approximate (since it uses finite test points).
Some functions like 3^n grow extremely fast, so values may overflow to inf for large n.