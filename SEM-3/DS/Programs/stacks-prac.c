#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Stack {
    int data[MAX];
    int top;
} stack;

stack createStack(stack* s) {
    s->top = -1;
}

int isFull(stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(stack* s) {
    return s->top == -1;
}

void push(stack* s, int data) {
    if (isFull(s)) {
        printf("Stack is Full\n");
        return;
    }
    s->data[++s->top] = data;
}

int pop(stack* s) {
    if (isEmpty(s)) {
        printf("Stack is Empty\n");
        return -1;
    }
    return s->data[s->top--];
}

void display(stack* s) {
    if (isEmpty(s)) {
        printf("Stack is Empty\n");
        return;
    }
    for (int i = s->top; i >= 0; --i) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int peek(stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    printf("%d\n", s->data[s->top]);
}

int main() {
    stack s = createStack(&s);
    int choice, data;
    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(&s, data);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                peek(&s);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
