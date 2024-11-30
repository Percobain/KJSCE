#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100

typedef struct Node {
    char name[MAX_NAME];
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

Node* createNode(char* name) {
    Node* node = malloc(sizeof(Node));
    if (!node) {
        printf("Memory Error");
        return NULL;
    }
    strcpy(node->name, name);
    node->next = NULL;
    return node;
}

void enqueue(Queue* q, char* name) {
    Node* node = createNode(name);
    if (q->tail == NULL) {
        q->head = node;
        q->tail = node;
    } else {
        q->tail->next = node;
        q->tail = node;
    }
    q->tail->next = q->head;
}

void dequeue(Queue* q) {
    if (q->head == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->head;
    if (q->head == q->tail) {
        q->head = NULL;
        q->tail = NULL;
    } else {
        q->head = q->head->next;
        q->tail->next = q->head;
    }
    free(temp);
}

int isEmpty(Queue* q) {
    return (q->head == NULL);
}

void printQueue(Queue* q) {
    Node* temp = q->head;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    do {
        printf("%s ", temp->name);
        temp = temp->next;
    } while (temp != q->head);
    printf("\n");
}

void josephus(Queue* q, int m) {
    Node* p = q->head;
    Node* prev = q->head;
    while (p->next != p) {
        int cnt = 1;
        while (cnt != m) {
            prev = p;
            p = p->next;
            cnt++;
        }
        prev->next = p->next;
        p = prev->next;
    }
    printf("The Last person Standing is %s\n", p->name);
}

int main() {
    int n, m;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the position to kill: ");
    scanf("%d", &m);
    Queue* q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    for (int i = 1; i <= n; ++i) {
        char name[MAX_NAME];
        printf("Enter Name %d:\n ", i);
        scanf("%s", name);
        enqueue(q, name);
    }
    printf("Initial Queue: ");
    printQueue(q);
    josephus(q, m);
    return 0;
}