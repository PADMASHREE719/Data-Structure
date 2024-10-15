#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int push(int stack[], int top, int value);
int pop(int stack[], int top);
void display(int stack[], int top);

int main() {
    int stack[MAX];
    int top = -1;

    int choice, value;

    while (1) {
        printf("\n*** Stack Operations ***\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                top = push(stack, top, value);
                break;
            case 2:
                top = pop(stack, top);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }

    return 0;
}

int push(int stack[], int top, int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
    return top;
}

int pop(int stack[], int top) {
    if (top == -1) {
        printf("Stack Underflow! No element to pop.\n");
    } else {
        printf("Element %d popped from the stack.\n", stack[top]);
        top--;
    }
    return top;
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
