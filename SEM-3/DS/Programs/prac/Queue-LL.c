#include <stdio.h>
#include <stdlib.h>

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
    if (front == NULL) printf("Queue is empty\n");
    else if (front == rear) front = rear = NULL;
    else  {
        printf("Deleted element is %d\n", front->data);
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
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                printf("Element is deleted\n");
                dequeue();
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