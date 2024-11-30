#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insert(Node* head, int data) {
    Node* node = createNode(data);
    Node* current = head;
    while (current->next != head && current->next->data < data) {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
}

void delete(Node* head, int data) {
    Node* current = head;
    while (current->next != head && current->next->data != data) {
        current = current->next;
    }
    if (current->next == head) {
        return;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void print(Node* head) {
    Node* current = head->next;
    while (current != head) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = createNode(0);
    head->next = head;
    int choice, data;
    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete(head, data);
                break;
            case 3:
                print(head);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}