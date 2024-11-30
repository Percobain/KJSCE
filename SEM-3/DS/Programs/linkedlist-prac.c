#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory Allocation failed\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


Node* createList() {
    Node* head = NULL;
    Node* temp = NULL;
    Node* newNode = NULL;
    int data;
    char ch = 'y';
    while (ch == 'y' || ch == 'Y') {
        printf("Enter Data: ");
        scanf("%d", &data);
        newNode = createNode(data);
        if (head == NULL) head = newNode;
        else temp->next = newNode;
        temp = newNode;

        while (getchar() != '\n') {
            printf("Do you want to continue? (y/n): ");
            scanf("%c", &ch);
        }
    }
}


void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


Node* insertAtBegin(Node* head, int el) {
    Node* newNode = createNode(el);
    if (head == NULL) head = newNode;
    else {
        newNode->next = head;
        head = newNode;
    }
    return head;
}


Node* insertAtEnd(Node* head, int el) {
    Node* newNode = createNode(el);
    if (head == NULL) head = newNode;
    else {
        Node* temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
    return head;
}


Node* insertAtKth(Node* head, int el, int k) {
    Node* newNode = createNode(el);
    Node* temp = head;
    int c = 1;
    while (c != k) {
        temp = temp->next;
        c++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}



Node* deleteBegin(Node* head) {
    if (head == NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}


Node* deleteEnd(Node* head) {
    if (head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}


Node* deleteKthNode(Node* head, int k) {
    if (head == NULL) return NULL;
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL) {
        cnt++;
        if (cnt == k) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}