#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void reverseString(char str[]) {
    int n = strlen(str);
    stack s;
    createStack(&s);
    for (int i = 0; i < n; ++i) {
        push(&s, str[i]);
    }
    for (int i = 0; i < n; ++i) {
        str[i] = pop(&s);
    }
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    gets(str);
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}