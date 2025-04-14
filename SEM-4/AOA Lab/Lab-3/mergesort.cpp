#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int l = low, r = mid + 1;
    while (l <= mid && r <= high) {
        if (arr[l] < arr[r]) {
            temp.push_back(arr[l++]);
        } else {
            temp.push_back(arr[r++]);
        }
    }
    while (l <= mid) {
        temp.push_back(arr[l++]);
    }
    while (r <= high) {
        temp.push_back(arr[r++]);
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int n; 
    cout << "Enter the elements of the array: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    mergeSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
}