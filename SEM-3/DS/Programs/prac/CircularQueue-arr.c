#include <stdio.h>
#include <stdlib.h>
#define n 5

int queue[n];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if ((rear + 1) % n == front) {
        printf("Queue is Full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear = (rear + 1) % n;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else if (front == rear) {
        printf("The deleted element is %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("The deleted element is %d\n", queue[front]);
        front = (front + 1) % n;
    }
}

void display() {
    int i = front;
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue is: \n");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % n;
        }
        printf("%d\n", queue[rear]);
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Peek element is %d\n", queue[front]);
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}