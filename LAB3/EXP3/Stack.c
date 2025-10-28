#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// ---------------- STACK FOR CHAR (operators) ----------------
char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

// ---------------- STACK FOR INT (operands) ----------------
int intStack[MAX];
int intTop = -1;

void pushInt(int x) {
    intStack[++intTop] = x;
}

int popInt() {
    return intStack[intTop--];
}

// ---------------- INFIX TO POSTFIX ----------------
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char ch;
    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {  // Operand (letter/number)
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (!isEmpty() && peek() != '(')
                postfix[k++] = pop();
            pop(); // Remove '('
        } else if (isOperator(ch)) {
            while (!isEmpty() && precedence(peek()) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    while (!isEmpty())
        postfix[k++] = pop();

    postfix[k] = '\0';
}

// ---------------- POSTFIX EVALUATION ----------------
int evaluatePostfix(char postfix[]) {
    int i, op1, op2, result;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        if (isdigit(ch)) {
            pushInt(ch - '0'); // Convert char to int
        } else if (isOperator(ch)) {
            op2 = popInt();
            op1 = popInt();
            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': {
                    result = 1;
                    for (int j = 0; j < op2; j++)
                        result *= op1;
                    break;
                }
            }
            pushInt(result);
        }
    }
    return popInt();
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter Infix Expression (single-digit operands only): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluation Result: %d\n", result);

    return 0;
}
