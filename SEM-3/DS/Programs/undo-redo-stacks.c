#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Stack implementation
typedef struct {
  char data[MAX];
  int top;
} Stack;

void initStack(Stack* stack) {
  stack->top = -1;
}

int isEmpty(Stack* stack) {
  return stack->top == -1;
}

int isFull(Stack* stack) {
  return stack->top == MAX - 1;
}

void push(Stack* stack, char ch) {
  if (isFull(stack))
    printf("Stack Full!!!!");
  else {
    stack->top++;
    stack->data[stack->top] = ch;
  }
}

char pop(Stack* stack) {
  if (isEmpty(stack))
    return -1;
  char ch = stack->data[stack->top];
  stack->top--;
  return ch;
}

// Undo/Redo system
typedef struct {
  Stack undoStack;
  Stack redoStack;
  char currentState[MAX];
} UndoRedoSystem;

void initUndoRedoSystem(UndoRedoSystem* system) {
  initStack(&system->undoStack);
  initStack(&system->redoStack);
}

void setState(UndoRedoSystem* system, char* state) {
  strcpy(system->currentState, state);
  push(&system->undoStack, state[0]); // store the first character of the state
}

void undo(UndoRedoSystem* system) {
  if (isEmpty(&system->undoStack))
    printf("Cannot undo!\n");
  else {
    char prevState = pop(&system->undoStack);
    push(&system->redoStack, system->currentState[0]);
    strcpy(system->currentState, &prevState);
  }
}

void redo(UndoRedoSystem* system) {
  if (isEmpty(&system->redoStack))
    printf("Cannot redo!\n");
  else {
    char nextState = pop(&system->redoStack);
    push(&system->undoStack, system->currentState[0]);
    strcpy(system->currentState, &nextState);
  }
}

void printState(UndoRedoSystem* system) {
  printf("Current state: %s\n", system->currentState);
}

int main() {
  UndoRedoSystem system;
  initUndoRedoSystem(&system);

  setState(&system, "Initial state");
  printState(&system);

  setState(&system, "State 1");
  printState(&system);

  setState(&system, "State 2");
  printState(&system);

  undo(&system);
  printState(&system);

  redo(&system);
  printState(&system);

  return 0;
}