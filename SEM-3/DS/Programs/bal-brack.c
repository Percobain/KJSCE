#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackEl {
    char bracket;
    struct StackEl* next;
} StackEl;

typedef struct Stack {
    StackEl* top;
} Stack;

// Function to create a new stack element
StackEl* createStackEl(char bracket) {
    StackEl* element = (StackEl*)malloc(sizeof(StackEl));
    element->bracket = bracket;
    element->next = NULL;
    return element;
}

// Function to push an element onto the stack
void push(Stack* stack, char bracket) {
    StackEl* element = createStackEl(bracket);
    element->next = stack->top;
    stack->top = element;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (stack->top == NULL) {
        return '\0';
    }
    char bracket = stack->top->bracket;
    StackEl* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return bracket;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to check if a bracket is an opening bracket
int isOpeningBracket(char bracket) {
    return bracket == '(' || bracket == '[' || bracket == '{';
}

// Function to check if a bracket is a closing bracket
int isClosingBracket(char bracket) {
    return bracket == ')' || bracket == ']' || bracket == '}';
}

// Function to check if a closing bracket matches an opening bracket
int matches(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

// Function to check if a sequence of brackets is balanced
int isBalanced(char* brackets) {
    Stack stack;
    stack.top = NULL;

    for (int i = 0; i < strlen(brackets); i++) {
        char bracket = brackets[i];
        if (isOpeningBracket(bracket)) {
            push(&stack, bracket);
        } else if (isClosingBracket(bracket)) {
            if (isEmpty(&stack)) {
                return 0; // Unmatched closing bracket
            }
            char opening = pop(&stack);
            if (!matches(opening, bracket)) {
                return 0; // Mismatched brackets
            }
        }
    }

    return isEmpty(&stack); // If the stack is empty, the brackets are balanced
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char brackets[100];
        fgets(brackets, 100, stdin);
        brackets[strcspn(brackets, "\n")] = 0; // Remove newline character

        if (isBalanced(brackets)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}





