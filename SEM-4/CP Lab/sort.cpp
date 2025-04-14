#include <bits/stdc++.h>
using namespace std;

class data {
    public:
    vector<int> arr;
    void readData() {
        int n;
        cout << "Enter number of elements: " << '\n';
        cin >> n;
        cout << "Enter elements: " << '\n';
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
    }

    void displayData() {
        if (arr.empty()) return;
        cout << "Array: ";
        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
};

class sorty {
    public:
    vector<int> selectionSort(vector<int> arr) {
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            int mini = i;
            for (int j = i+1; j < n; ++j) {
                if (arr[j] < arr[mini]) {
                    mini = j;
                }
            }
            swap(arr[i], arr[mini]);
        }
        return arr;
    }

    public:
    vector<int> insertionSort(vector<int> arr) {
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j = j - 1;
            }
            arr[j+1] = key;
        }
        return arr;
    }
};

int main() {
    data d = data();
    sorty s = sorty();

    d.readData();
    d.displayData();

    vector<int> arr = d.arr;
    vector<int> selectionSortedArr = s.selectionSort(arr);
    vector<int> insertionSortedArr = s.insertionSort(arr);

    cout << "Selection Sorted Array: ";
    for (int i = 0; i < selectionSortedArr.size(); ++i) {
        cout << selectionSortedArr[i] << " ";
    }
    cout << '\n';

    cout << "Insertion Sorted Array: ";
    for (int i = 0; i < insertionSortedArr.size(); ++i) {
        cout << insertionSortedArr[i] << " ";
    }
    cout << '\n';

    return 0;
}