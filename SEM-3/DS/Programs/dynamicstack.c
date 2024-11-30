#include <stdio.h>
#include <stdlib.h>

typedef struct StackEl {
    int data;
    struct StackEl* next;
} StackEl;

typedef struct Stack {
    StackEl* top;
    int size;
} Stack;

// Function to create a new stack element
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// Function to insert an element at the top of the stack
void insert(Stack* stack, int data) {
    StackEl* element = (StackEl*)malloc(sizeof(StackEl));
    element->data = data;
    element->next = stack->top;
    stack->top = element;
    stack->size++;
}

// Function to remove an element from the top of the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = stack->top->data;
    StackEl* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

// Function to peek at the top element of the stack
int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

// Function to display the stack
void display(Stack* stack) {
    StackEl* temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to check if stack is empty
int isEmpty(Stack* stack) {
    return stack->size == 0;
}

int main() {
    Stack* stack = createStack();
    int choice, data;

    while (1) {
        printf("Stack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                insert(stack, data);
                break;
            case 2:
                data = pop(stack);
                if (data != -1) {
                    printf("Popped: %d\n", data);
                }
                break;
            case 3:
                data = peek(stack);
                if (data != -1) {
                    printf("Peek: %d\n", data);
                }
                break;
            case 4:
                printf("Stack: ");
                display(stack);
                break;
            case 5:
                printf("Is stack empty? %s\n", isEmpty(stack) ? "Yes" : "No");
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}