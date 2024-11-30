#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct Stack{
    int data[MAX_SIZE];
    int top;
} Stack;

Stack createStack() { // Function to create a stack
    Stack newStack;
    newStack.top = -1;
    return newStack;
}

int isFull(Stack *stack) { // Function to check if stack is full
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(Stack *stack) { // Function to check if stack is empty
    return stack->top == -1;
}

void push(Stack *stack, int data) { // Function to push data into stack & increase top by 1
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->data[++stack->top] = data;
}

int pop(Stack* stack) { // Function to pop data from stack & decrease top by 1
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top--];
}

void display(Stack* stack) { // Function to display stack elements
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int peek(Stack* stack) { // Function to display top element of stack
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    printf("%d\n", stack->data[stack->top]);
}

int main() {
    Stack stack = createStack();
    int choice, data;

    while (1) {
        printf("Stack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter data: ");
                scanf("%d", &data);
                push(&stack, data);
                break;

            case 2:
                data = pop(&stack);
                if (data != -1) {
                    printf("Popped element: %d\n", data);
                }
                break;

            case 3:
                display(&stack);
                break;
            
            case 4:
                data = peek(&stack);
                peek(&stack);
                break;
            
            case 5:
                printf("Exiting\n");
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}


