#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* root;
} BST;

BST* create() {
    BST* bst = (BST*)malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

BST* insert(BST* bst, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    if (bst->root == NULL) {
        bst->root = node;
    } else {
        Node* curr = bst->root;
        Node* parent = NULL;

        while(curr != NULL) {
            parent = curr;
            if (data < curr->data) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        if (data < parent->data) {
            parent->left = node;
        } else {
            parent->right = node;
        }
    }
    return bst;
}

void search(BST* bst, int data) {
    Node* curr = bst->root;
    while (curr != NULL) {
        if (data == curr->data) {
            printf("Found %d in the BST\n", data);
            return;
        } else if (data < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    printf("%d not found in the BST\n", data);
}

void inorder(Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void preorder(Node* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(Node* node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

int main() {
    BST* bst = create();

    int choice, data;
    while (1) {
        printf("1. Insert node\n");
        printf("2. Search for node\n");
        printf("3. Perform inorder traversal\n");
        printf("4. Perform preorder traversal\n");
        printf("5. Perform postorder traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                bst = insert(bst, data);
                break;
            case 2:
                printf("Enter the value to search for: ");
                scanf("%d", &data);
                search(bst, data);
                break;
            case 3:
                printf("Inorder: ");
                inorder(bst->root);
                printf("\n");
                break;
            case 4:
                printf("Preorder: ");
                preorder(bst->root);
                printf("\n");
                break;
            case 5:
                printf("Postorder: ");
                postorder(bst->root);
                printf("\n");
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
