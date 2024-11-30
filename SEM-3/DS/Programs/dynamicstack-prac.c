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


Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void insert(Stack* s, int data) {
    StackEl* el = (StackEl*)malloc(sizeof(StackEl));
    el->data = data;
    el->next = s->top;
    s->top = el;
    s->size++;
}

int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is Empty\n");
        return -1;
    }
    int data = s->top->data;
    StackEl* temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return data;
}


int peek(Stack* s) {
    StackEl* temp = s->top;
    if(s->top == NULL) {
        printf("Stack is empty");
        return -1;
    }
    return s->top->data;
}

void display(Stack* s) {
    StackEl* temp = s->top;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int isEmpty(Stack* stack) {
    return stack->size == 0;
}


int main() {
    Stack* s = createStack();
    int choice, data;
    while(1) {
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
                insert(s, data);
                break;
            case 2:
                data = pop(s);
                if (data != -1) {
                    printf("Popped: %d\n", data);
                }
                break;
            case 3:
                data = peek(s);
                if (data != -1) {
                    printf("Peek: %d\n", data);
                }
                break;
            case 4:
                printf("Stack: ");
                display(s);
                break;
            case 5:
                printf("Is stack empty? %s\n", isEmpty(s) ? "Yes" : "No");
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}