#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data; 
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list
Node* createList() {
    Node* head = NULL;
    Node* temp = NULL;
    Node* newNode = NULL;
    int data;
    char ch = 'y';
    while (ch == 'y' || ch == 'Y') {
        printf("Enter data: ");
        scanf("%d", &data);
        newNode = createNode(data);
        if (head == NULL) head = newNode;
        else temp->next = newNode;
        temp = newNode;

        while (getchar() != '\n');
        printf("Do you want to continue? (y/n): ");
        scanf("%c", &ch);
    }
    return head;
}

// Function to display the linked list
void printList(Node* head) {
    Node* temp = head;
    while(temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    Node* head = createList();
    printf("Original list: ");
    printList(head);
    head = reverseList(head);
    printf("Reversed list: ");
    printList(head);
    return 0;
}