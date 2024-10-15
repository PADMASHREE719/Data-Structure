#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(char stack[], char value);
char pop(char stack[]);
int precedence(char operator);
void infixToPostfix(char infix[], char postfix[]);

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
void push(char stack[], char value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %c\n", value);
    } else {
        top++;
        stack[top] = value;
    }
}
char pop(char stack[]) {
    if (top == -1) {
        printf("Stack Underflow! No element to pop.\n");
        return '\0'; // Return null character in case of underflow
    } else {
        char poppedValue = stack[top];
        top--;
        return poppedValue;
    }
}
int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
void infixToPostfix(char infix[], char postfix[]) {
    char stack[MAX];
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char symbol = infix[i];
        if (isalnum(symbol)) {
            postfix[j] = symbol;
            j++;
        }
        else if (symbol == '(') {
            push(stack, symbol);
        }
        else if (symbol == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack);
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(symbol)) {
                postfix[j++] = pop(stack);
            }
            push(stack, symbol);
        }
        i++;
    }
    while (top != -1) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
}
