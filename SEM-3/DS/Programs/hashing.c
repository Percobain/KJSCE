#include <stdio.h>
#include <stdlib.h>
#define n 10

typedef struct {
    int key;
    int isOccupied; // 0 if empty, 1 if occupied
} hashEntry;

hashEntry hashTable[n];

int hash(int key) {
    return key % n;
}

int linearProbing(int key) {
    int index = hash(key);
    int collisions = 0;
    while (hashTable[index].isOccupied) {
        collisions++;
        index = (index + 1) % n;
    }
    hashTable[index].key = key;
    hashTable[index].isOccupied = 1;
    return collisions;

}

int linearProbingSearch(int key) {
    int index = hash(key);
    while (hashTable[index].isOccupied) {
        if (hashTable[index].key == key) return index;
        index = (index + 1) % n;
    }
    return -1;
}

int quadraticProbing(int key) {
    int index = hash(key);
    int collisions = 0;
    int i = 1;
    while (hashTable[index].isOccupied) {
        collisions++;
        i++;
        index = (index + i * i) % n;
    }
    hashTable[index].key = key;
    hashTable[index].isOccupied = 1;
    return collisions;
}

int quadraticProbingSearch(int key) {
    int index = hash(key);
    int i = 0;
    while (hashTable[index].isOccupied) {
        if (hashTable[index].key == key) return index;
        i++;
        index = (hash(key) + i * i) % n;
    }
    return -1;
}

void display() {
    printf("Hash Table: \n");
    for (int i = 0; i < n; ++i) {
        if (hashTable[i].isOccupied) {
            printf("Index %d: %d\n", i, hashTable[i].key);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    int choice, key, collisions;

    for (int i = 0; i < n; ++i) {
        hashTable[i].isOccupied = 0;
    }

    do {
        printf("\nMenu:\n");
        printf("1. Linear Probing Insertion\n");
        printf("2. Linear Probing Search\n");
        printf("3. Quadratic Probing Insertion\n");
        printf("4. Quadratic Probing Search\n");
        printf("5. Display Hash Table\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                collisions = linearProbing(key);
                printf("Key %d inserted with %d collisions.\n", key, collisions);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int searchIndex = linearProbingSearch(key);
                if (searchIndex != -1) {
                    printf("Key %d found at index %d.\n", key, searchIndex);
                } else {
                    printf("Key %d not found.\n", key);
                }
                break;
            
            case 3:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                collisions = quadraticProbing(key);
                printf("Key %d inserted with %d collisions.\n", key, collisions);
                break;

            case 4:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int oo = quadraticProbingSearch(key);
                if (oo != -1) {
                    printf("Key %d found at index %d.\n", key, oo);
                } else {
                    printf("Key %d not found.\n", key);
                }
                break;
            
            case 5:
                display();
                break;
            
            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    while (choice != 6);
    return 0;
}