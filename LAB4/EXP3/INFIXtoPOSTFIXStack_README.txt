Infix to Postfix Conversion & Evaluation in C
=============================================

Overview
-----------
This program performs two operations:
1. Convert an **Infix expression** (e.g., (3+5)*2 ) into **Postfix expression** (Reverse Polish Notation).
2. Evaluate the Postfix expression to get the final result.

Restrictions:
- Operands must be **single-digit numbers (0–9)** or variables (like A, B, C).
- Operators supported: +, -, *, /, ^ 
- Parentheses `(` and `)` are handled.


Input Format
-------------------------------------------------
- Enter a valid **infix expression** (no spaces).
- Example: `(3+5)*2` or `9-5+2`.


-------------------------------------------------
Time & Space Complexity
-------------------------------------------------
1. Conversion (Infix → Postfix):
- Time: O(n)
- Space: O(n) (stack)

2. Evaluation (Postfix):
- Time: O(n)
- Space: O(n) (stack)

-------------------------------------------------
Notes
-------------------------------------------------
- For multi-digit numbers, the program needs modification (currently processes one digit at a time).
- Operator precedence:
^ (highest), * /, + - (lowest).
- Left-to-right associativity except exponentiation (^).
