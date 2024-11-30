#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* lastNode = *head;
    while (lastNode->next) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
}

// Function to remove duplicates from the list
void removeDuplicates(Node* head) {
    Node* current = head;
    while (current) {
        Node* runner = current;
        while (runner->next) {
            if (runner->next->data == current->data) {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int n, i, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertNode(&head, data);
    }

    printf("Original List: ");
    printList(head);

    // Remove duplicates from the list
    removeDuplicates(head);

    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}