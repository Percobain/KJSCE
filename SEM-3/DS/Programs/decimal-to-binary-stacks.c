#include <stdio.h>
#include <stdlib.h>
#define MAX 100

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

void push(stack *s, char item) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    } 
    s->data[++s->top] = item;
}

char pop(stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top--];
}

void decimalToBinary(int n) {
    stack s;
    createStack(&s);
    if (n == 0) {
        printf("0\n");
        return;
    }
    while (n > 0) {
        int rem = n % 2;
        push(&s, rem);
        n /= 2;
    }

    printf("Binary equivalent: ");
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");
}


int main() {
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    decimalToBinary(n);
    return 0;
}
