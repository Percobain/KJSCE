#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j <=i; ++j) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 0; i <= n-1; ++i) {
        int j = i;
        while (j > 0 && arr[j] < arr[j-1]) {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

void shellSort(int arr[], int n) {
    for (int gap = n /2; gap > 0; gap/= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for(j = i; j >= gap && arr[j-gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int n;
    printf("Enter Number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    
    shellSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}