#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* addToEmpty(Node* head, int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    head = temp;
    return head;
}

Node* insertAtBegin(Node* head, int data) {
    if (head == NULL) return addToEmpty(head, data);
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

Node* insertAtKthPos(Node* head, int data, int pos) {
    if (pos == 1) return insertAtBegin(head, data);
    Node* newNode = NULL;
    Node* temp = head;
    Node* temp2 = NULL;
    newNode = addToEmpty(newNode, data);
    while (pos != 1) {
        temp = temp->next;
        pos--;
    }
    temp2 = temp->next;
    temp->next = newNode;
    temp2->prev = newNode;
    newNode->prev = temp;
    newNode->next = temp2;
    return head;
}

Node* insertAtEnd(Node* head, int data) {
    if (head == NULL) return addToEmpty(head, data);
    Node* temp = (Node*)malloc(sizeof(Node));
    Node* tp;
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    tp = head;
    while(tp->next != NULL) {
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;
    return head;
}

Node* deleteAtBegin(Node* head) {
    if (head == NULL) return head;
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}

Node* deleteAtEnd(Node* head) {
    if (head == NULL) return head;
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return head;
}


Node* deleteAtKthPos(Node* head, int pos) {
    if (pos == 1) return deleteAtBegin(head);
    Node* temp = head;
    Node* temp2 = NULL;
    while (pos > 1 && temp != NULL) {
        temp = temp->next;
        pos--;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return head;
    }
    if (temp->next == NULL) {
        return deleteAtEnd(head);
    } else {
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void search(Node* head, int data) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("Element found at position %d\n", pos);
            return;
        }
        pos++;
        temp = temp->next;
    }
    printf("Element not found\n");
}


int main() {
    int choice, val, pos;
    Node* head = NULL;
    while (1) {
        printf("1. Insert at begin\n");
        printf("2. Insert at kth position\n");
        printf("3. Insert at end\n");
        printf("4. Delete at begin\n");
        printf("5. Delete at kth position\n");
        printf("6. Delete at end\n");
        printf("7. Print list\n");
        printf("8. Search\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                head = insertAtBegin(head, val);
                break;
            
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                printf("Enter position: ");
                scanf("%d", &pos);
                head = insertAtKthPos(head, val, pos);
                break;
            
            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                head = insertAtEnd(head, val);
                break;
            
            case 4:
                head = deleteAtBegin(head);
                break;
            
            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = deleteAtKthPos(head, pos);
                break;
            
            case 6:
                head = deleteAtEnd(head);
                break;
            
            case 7:
                printList(head);
                break;
            
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(head, val);
                break;
            
            case 9:
                exit(0);
            
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}