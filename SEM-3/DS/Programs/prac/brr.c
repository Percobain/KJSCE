#include <stdio.h>
#include <stdlib.h>

// #define n 5

// int queue[n];
// int front = -1;
// int rear = -1;

// void enqueue(int x) {
//     if (rear == n - 1) printf("Queue is full\n");
//     else if (front == -1 && rear == -1) front = rear = 0;
//     else {
//         rear++;
//         queue[rear] = x;
//     }
// }

// void dequeue() {
//     if (front == -1 && rear == -1) printf("Queue is Empty\n");
//     else if (front == rear) front = rear = -1;
//     else {
//         printf("Deleted Element is %d", queue[front]);
//         front++;
//     }
// }

// void display() {
//     if (front == -1 && rear == -1) printf("Queue is Empty\n");
//     else {
//         for (int i = front; i <= rear; ++i) {
//             printf("%d ", queue[i]);
//         }
//         printf("\n");
//     }
// }

// void peek() {
//     if (front == -1 && rear == -1) printf("Queue is Empty\n");
//     else {
//         printf("Peek Elemenet is: %d", queue[front]);
//     }
// }


typedef struct Node {
    int data;
    struct Node *next;
} Node;

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    if (front == NULL && rear == NULL) front = rear = temp;
    else {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue() {
    Node* temp = front;
    if (front == NULL) printf("Queue is Empty\n");
    else if (front == rear) front = rear = NULL;
    else {
        printf("Deleted Element is: %d", front->data);
        front = front->next;
        free(temp);
    }
}

void display() {
    Node* temp = front;
    if (front == NULL) printf("Queue is empty\n");
    else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void peek() {
    if (front == NULL) printf("Queue is empty\n");
    else printf("Peek element is %d\n", front->data);
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
                printf("Enter the value to insert: ");
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
                break;
            
            default:
                printf("Invalid Choice!");
                break;
        }
    }
    return 0;
}



