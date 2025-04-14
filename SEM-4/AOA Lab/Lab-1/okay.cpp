#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;


void selectionSort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); ++i) {
        int mini = i;
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
    }
}

void insertionSort(vector<int> &arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int j = i;
        while (j > 0 && arr[j] < arr[j-1]) {
            swap(arr[j], arr[j-1]);
            --j;
        }
    }
}

vector<int> generateRandomArray(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
    }
    return arr;
}

int main() {
    ofstream file("output.csv");
    file << "n,bubble,selection,insertion,merge\n";

    for (int i = 1000; i <= 10000; i+=1000) {
        vector<int> arr = generateRandomArray(i);
        vector<int> arr1 = arr;
        vector<int> arr2 = arr;
        vector<int> arr3 = arr;

        auto start1 = chrono::high_resolution_clock::now();
        selectionSort(arr1);
        auto end1 = chrono::high_resolution_clock::now();
        double time_taken1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();

        auto start2 = chrono::high_resolution_clock::now();
        insertionSort(arr2);
        auto end2 = chrono::high_resolution_clock::now();
        double time_taken2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2).count();

        file << i << "," << time_taken1 << "," << time_taken2 <<"\n";
    }
    file.close();
}