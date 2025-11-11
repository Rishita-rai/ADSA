B-Tree Implementation in C

This program implements a B-Tree (balanced search tree used in databases and file systems) with:

Insertion of keys

Traversal (inorder-like, left-to-right)

Search functionality (in code, not in menu)

The B-Tree is parameterized by minimum degree T, here set as T = 3.

Features

Each node can store up to 2*T - 1 keys.

Automatically splits full nodes during insertion.

Balanced structure ensures logarithmic time complexity.

Menu-driven interface.



Menu Options
--- B-Tree Operations ---
1. Insert
2. Traverse
3. Exit


Time & Space Complexity

Insertion: O(t log n) where t = degree (here 3)

Traversal: O(n)

Search: O(log n)

Space Complexity: O(n)