Sorting Algorithms in C (Quick, Merge, Heap)
============================================

Overview
-----------
This program implements three popular sorting algorithms:
1. Quick Sort
2. Merge Sort
3. Heap Sort

The user can choose which sorting method to apply to a given array of integers.  

-------------------------------------------------
Time & Space Complexity
-------------------------------------------------
1. Quick Sort:
- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n^2)
- Space: O(log n) (recursion)

2. Merge Sort:
- Best/Average/Worst Case: O(n log n)
- Space: O(n) (auxiliary arrays)

3. Heap Sort:
- Best/Average/Worst Case: O(n log n)
- Space: O(1) (in-place)

-------------------------------------------------
Notes
-------------------------------------------------
- Quick Sort is usually fastest on average but can degrade on sorted inputs.
- Merge Sort is stable and guarantees O(n log n), but uses extra memory.
- Heap Sort is in-place but often slower in practice compared to Quick Sort.
- The program prints the sorted array in ascending order.
