Binary Search Tree (BST) in C
=============================
Overview
-----------
This program implements a **Binary Search Tree (BST)** in C with the following operations:
1. Insert a node
2. Delete a node
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal

A Binary Search Tree is a hierarchical data structure in which each node has:
- Left child < Root < Right child
- Efficient for searching, insertion, and deletion operations.

Menu-Driven Options
-------------------------------------------------
- `1` → Insert a value into BST
- `2` → Delete a value from BST
- `3` → Inorder Traversal (Left → Root → Right)
- `4` → Preorder Traversal (Root → Left → Right)
- `5` → Postorder Traversal (Left → Right → Root)
- `6` → Exit the program

-------------------------------------------------


-------------------------------------------------
Time & Space Complexity
-------------------------------------------------
1. Insertion:
- Average Case: O(log n)
- Worst Case: O(n) (when tree is skewed)

2. Deletion:
- Average Case: O(log n)
- Worst Case: O(n)

3. Traversals:
- Time: O(n)
- Space: O(h), where h = height of tree

-------------------------------------------------
 Notes
-------------------------------------------------
- This is a **menu-driven program**, keeps running until Exit (choice 6).
- Inorder traversal gives elements in **sorted order**.
- Deletion handles:
- Node with no child (leaf node)
- Node with one child
- Node with two children (replaced by inorder successor).
