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

// Function to insert a new element at the beginning of the linked list
Node* insertAtBegin(Node* head, int el) {
    Node* newNode = createNode(el);
    if (head == NULL) head = newNode;
    else {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Function to insert a new element at the end of the linked list
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

// Function to insert a new element at next position in the linked list
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

// Function to delete the first element of the linked list
Node* deleteBegin(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    else {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

// Function to delete the last element of the linked list
Node* deleteEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    else if (head->next == NULL) {
        free(head);
        head = NULL;
    }
    else {
        Node* temp = head;
        while(temp->next->next != NULL) temp = temp->next;
        free(temp->next);
        temp->next = NULL;
    }
    return head;
}

// Function to delete the kth element of the linked list
// Node* deleteElement(Node* head, int k) {
//     if (head == NULL) {
//         printf("List is empty\n");
//         return head;
//     }
//     else if (k == 1) {
//         Node* temp = head;
//         head = head->next;
//         free(temp);
//     }
//     else {
//         Node* temp = head;
//         int cnt = 1;
//         while (temp != NULL && cnt < k-1) {
//             temp = temp->next;
//             cnt++;
//         }
//         if (temp != NULL && temp->next != NULL) {
//             Node* delNode = temp->next;
//             temp->next = delNode->next;
//             free(delNode);
//         }
//         else {
//             printf("Invalid position\n");
//         }
//     }
//     return head;
// }

Node* deleteValue(Node* head, int el) {
    if (head == NULL) return NULL;
    if (head->data == el) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL) {
        if (temp->data == el) {
            prev->next = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Function to search for an element in the linked list
void search(Node* head, int el) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == el) {
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Element not found\n");
}

// Function to find the length of the linked list
void lengthofLL(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while(temp) {
        cnt++;
        temp = temp->next;
    }
    printf("Length of the linked list is: %d\n", cnt);
}

int main() {
    Node* head = NULL;
    int choice, el;
    while (1) {
        printf("Menu:\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Search for an element\n");
        printf("4. Insert at beginning\n");
        printf("5. Insert at end\n");
        printf("6. Insert at kth position\n");
        printf("7. Delete from beginning\n");
        printf("8. Delete from end\n");
        printf("9. Delete a value: \n");
        printf("10. Length of linked list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = createList();
                break;
            case 2:
                printList(head);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &el);
                search(head, el);
                break;
            case 4:
                printf("Enter element to insert at beginning: ");
                scanf("%d", &el);
                head = insertAtBegin(head, el);
                break;
            case 5:
                printf("Enter element to insert at end: ");
                scanf("%d", &el);
                head = insertAtEnd(head, el);
                break;
            case 6:
                printf("Enter element to insert: ");
                scanf("%d", &el);
                printf("Enter position: ");
                scanf("%d", &choice);
                head = insertAtKth(head, el, choice);
                break;
            case 7:
                head = deleteBegin(head);
                break;
            case 8:
                head = deleteEnd(head);
                break;
            case 9:
                printf("Enter element to delete: ");
                scanf("%d", &el);
                deleteValue(head, el);
                break;
            case 10:
                lengthofLL(head);
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}