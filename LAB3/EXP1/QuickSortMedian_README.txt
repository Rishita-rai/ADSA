Quick Sort in C (Median-of-Three Pivot)
=======================================

Overview
-----------
This program implements **Quick Sort** using the **Median-of-Three pivot selection strategy**.  
The pivot is chosen as the median of the first, middle, and last elements to reduce the chance of worst-case behavior (which occurs when input is already sorted or nearly sorted).  


Time & Space Complexity
-------------------------------------------------
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n^2) (rare, mostly for adversarial inputs)
- **Space Complexity:** O(log n) (recursive stack)

-------------------------------------------------
Notes
-------------------------------------------------
- The program uses **median-of-three** to select pivot for better performance.
- For very small partitions (size ≤ 3), the program uses simple comparisons instead of full partitioning.
- The output is printed as a sorted array in ascending order.
