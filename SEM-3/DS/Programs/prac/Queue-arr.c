#include <stdio.h>
#include <stdlib.h>

#define n 5

int queue[n];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (rear == n - 1) printf("Queue is full\n");
    else if (front == -1 && rear == -1) front = rear = 0;
    else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) printf("Queue is empty\n");
    else if (front == rear) front = rear = -1;
    else {
        printf("Deleted element is %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 && rear == -1) printf("Queue is Empty\n");
    else {
        for (int i = front; i <= rear; ++i) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void peek() {
    if (front == -1 && rear == -1) printf("Queue is Empty\n");
    else printf("Peek element is %d\n", queue[front]);
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

        switch(choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            
            case 2:
                dequeue();
                printf("Element is deleted\n");
                break;
            
            case 3:
                printf("Queue is: ");
                display();
                break;

            case 4:
                printf("Peek element is: ");
                peek();
                break;

            case 5:
                exit(0);
                break;
            
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}