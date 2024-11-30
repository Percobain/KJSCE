#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int data;
    struct BST *left, *right;
} BST;

BST* createNewNode(int val) {
    BST *newnode = (BST *)malloc(sizeof(BST));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

BST* insert(BST* root, int val) {
    if (root == NULL) return createNewNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

void preorder(BST* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(BST* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(BST* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

BST* search(BST* root, int val) {
    if (root == NULL || root->data == val) return root;
    if (val < root->data) return search(root->left, val);
    return search(root->right, val);
}

int main() {
    int choice, val;
    BST *root = NULL;
    while (1) {
        printf("Menu: \n");
        printf("1. Insert\n");
        printf("2. Preorder\n");
        printf("3. Inorder\n");
        printf("4. Postorder\n");
        printf("5. Search\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            
            case 2:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            
            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter the value to search: ");
                scanf("%d", &val);
                if (search(root, val) != NULL) printf("Found\n");
                else printf("Not Found\n");
                break;
            
            case 6:
                exit(0);
                break;
            
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}