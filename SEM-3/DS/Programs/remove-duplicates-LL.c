#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) *head = newNode;
    else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void removeDuplicates(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        Node* runner = current;
        while(runner->next != NULL) {
            if (runner->next->data == current->data) {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            }
            else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


int main() {
    Node* head = NULL;

    // Create the list: 1->2->2->5->6->5
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 2);
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 5);

    printf("Original List: ");
    printList(head);

    removeDuplicates(&head);

    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}