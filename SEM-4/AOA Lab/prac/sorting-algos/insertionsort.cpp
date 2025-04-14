#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int n) {
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

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    insertionSort(arr, n);
    for (int i = 0; i < n; ++i) cout << arr[i] << " "; 
}