Binary Search in C (Recursive & Iterative)
=================================================


-----------
This program demonstrates **Binary Search** using both **Recursive** and **Iterative** approaches.

Binary Search works on **sorted arrays** by repeatedly dividing the search range into half until the key element is found or the search range becomes empty.


Input Format
-------------------------------------------------
1. Number of elements `n`.
2. `n` sorted integers (in ascending order).
3. Key element to search.
4. Choice of search method:
   - `1` → Recursive Binary Search
   - `2` → Iterative Binary Search



-------------------------------------------------
Time & Space Complexity
-------------------------------------------------
- Best Case: O(1)
- Worst Case: O(log n)
- Average Case: O(log n)

Space Complexity:
- Recursive: O(log n) (stack space)
- Iterative: O(1)

- Input array **must be sorted** for binary search to work correctly.
- The program prints **0-based index** of the found key.
- If the key is not found, it prints a message accordingly.

