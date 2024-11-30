#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* insertAtBegin(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    else {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        return newNode;
    }
}

Node* insertAtKthPos(Node* head, int data, int pos) {
    if (pos == 1) return insertAtBegin(head, data);
    Node* newNode = createNode(data);
    Node* temp = head;
    while (pos != 1) {
        temp = temp->next;
        pos--;
    }
    Node* prevNode = temp->prev;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = temp;
    temp->prev = newNode;
    return head;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->prev = newNode;
        newNode->next = newNode;
        return newNode;
    }
    else {
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        return head;
    }
}

Node* deleteAtBegin(Node* head) {
    if (head == NULL) return NULL;
    if (head->next == head) {
        free(head);
        return NULL;
    }
    Node* tail = head->prev;
    Node* newHead = head->next;
    newHead->prev = tail;
    tail->next = newHead;
    free(head);
    return newHead;
}

Node* deleteAtKthPos(Node* head, int pos) {
    if (pos == 1) return deleteAtBegin(head);
    Node* temp = head;
    while (pos != 1) {
        temp = temp->next;
        pos--;
    }
    Node* prevNode = temp->prev;
    Node* nextNode = temp->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    free(temp);
    return head;
}

Node* deleteAtEnd(Node* head) {
    if (head == NULL) return NULL;
    if (head->next == head) {
        free(head);
        return NULL;
    }
    Node* tail = head->prev;
    Node* newTail = tail->prev;
    newTail->next = head;
    head->prev = newTail;
    free(tail);
    return head;
}

void display(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice, value, pos;
    Node* head = NULL;
    while (1) {
        printf("1. Insert at beginning\n");
        printf("2. Insert at kth position\n");
        printf("3. Insert at end\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at kth position\n");
        printf("6. Delete at end\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                head = insertAtBegin(head, value);
                break;
            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                printf("Enter the position: ");
                scanf("%d", &pos);
                head = insertAtKthPos(head, value, pos);
                break;
            case 3:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 4:
                head = deleteAtBegin(head);
                break;
            case 5:
                printf("Enter the position: ");
                scanf("%d", &pos);
                head = deleteAtKthPos(head, pos);
                break;
            case 6:
                head = deleteAtEnd(head);
                break;
            case 7:
                display(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}