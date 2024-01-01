#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char ch) {
    switch (ch) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}

void infixToPostfix(char infix[]) {
    char postfix[MAX_SIZE];
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top != -1 && stack[top] == '(') {
                pop();
            } else {
                printf("Invalid expression\n");
                exit(1);
            }
        } else if (isOperator(infix[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        } else {
            printf("Invalid character in expression\n");
            exit(1);
        }
    }

    while (top != -1) {
        if (stack[top] == '(') {
            printf("Invalid expression\n");
            exit(1);
        }
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX_SIZE];

    printf("Enter a valid parenthesized infix arithmetic expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
