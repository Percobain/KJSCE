// #include <bits/stdc++.h>
// using namespace std;

// int n = 10;
// int m = 10;

// int a[0][0];
// int b[0][0];
// int c[0][0];

// // For Addition of 3x3 matrices

// int Brute() {
//     c[0][0] = a[0][0] + b[0][0];
//     c[0][1] = a[0][1] + b[0][1];
//     c[0][2] = a[0][2] + b[0][2];

//     c[1][0] = a[1][0] + b[1][0];
//     c[1][1] = a[1][1] + b[1][1];
//     c[1][2] = a[1][2] + b[1][2];

//     c[2][0] = a[2][0] + b[2][0];
//     c[2][1] = a[2][1] + b[2][1];
//     c[2][2] = a[2][2] + b[2][2];
// }

// int Better() {
//     for (int j = 0; j <= 2; ++j) {
//         c[0][j] = a[0][j] + b[0][j];
//     }
//     for (int j = 0; j <= 2; ++j) {
//         c[1][j] = a[1][j] + b[1][j];
//     }
//     for (int j = 0; j <= 2; ++j) {
//         c[2][j] = a[2][j] + b[2][j];
//     }
// }

// int Optimized() {
//     for (int i = 0; i <= 2; ++i) {
//         for (int j = 0; j <= 2; ++j) {
//             c[i][j] = a[i][j] + b[i][j];
//         }
//     }
// }


// // For Multiplication of 3x3 matrices

// int Brute1() {
//     c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0] + a[0][2] * b[2][0];
//     c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1] + a[0][2] * b[2][1];
//     c[0][2] = a[0][0] * b[0][2] + a[0][1] * b[1][2] + a[0][2] * b[2][2];

//     c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0] + a[1][2] * b[2][0];
//     c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1] + a[1][2] * b[2][1];
//     c[1][2] = a[1][0] * b[0][2] + a[1][1] * b[1][2] + a[1][2] * b[2][2];

//     c[2][0] = a[2][0] * b[0][0] + a[2][1] * b[1][0] + a[2][2] * b[2][0];
//     c[2][1] = a[2][0] * b[0][1] + a[2][1] * b[1][1] + a[2][2] * b[2][1];
//     c[2][2] = a[2][0] * b[0][2] + a[2][1] * b[1][2] + a[2][2] * b[2][2];
// }


// int Better1() {
//     for (int j = 0; j <= 2; ++j) {
//         c[0][j] = a[0][0] * b[0][j] + a[0][1] * b[1][j] + a[0][2] * b[2][j];
//     }
//     for (int j = 0; j <= 2; ++j) {
//         c[1][j] = a[1][0] * b[0][j] + a[1][1] * b[1][j] + a[1][2] * b[2][j];
//     }
//     for (int j = 0; j <= 2; ++j) {
//         c[2][j] = a[2][0] * b[0][j] + a[2][1] * b[1][j] + a[2][2] * b[2][j];
//     }
// }

// int Optimized1() {
//     for (int i = 0; i <= 2; ++i) {
//         for (int j = 0; j <= 2; ++j) {
//             c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
//         }
//     }
// }



#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[]) {
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void brute(int arr[]) {
    int t, temp;

    t = 0;
    if (arr[t] > arr[1]) t = 1;
    if (arr[t] > arr[2]) t = 2;
    if (arr[t] > arr[3]) t = 3;
    if (arr[t] > arr[4]) t = 4;
    temp = arr[0]; 
    arr[0] = arr[t];
    arr[t] = temp;

    t = 1;
    if (arr[t] > arr[2]) t = 2;
    if (arr[t] > arr[3]) t = 3;
    if (arr[t] > arr[4]) t = 4;
    temp = arr[1]; 
    arr[1] = arr[t]; 
    arr[t] = temp;

    t = 2;
    if (arr[t] > arr[3]) t = 3;
    if (arr[t] > arr[4]) t = 4;
    temp = arr[2]; 
    arr[2] = arr[t]; 
    arr[t] = temp;

    t = 3;
    if (arr[t] > arr[4]) t = 4;
    temp = arr[3]; 
    arr[3] = arr[t]; 
    arr[t] = temp;
  
}

void opt(int arr[]) {
    for (int i = 0; i < 4; i++) { 
        int t = i; 
        for (int j = i + 1; j < 5; j++) { 
            if (arr[j] < arr[t]) {
                t = j; 
            }
        }
        int temp = arr[i];
        arr[i] = arr[t];
        arr[t] = temp;
    }
}

int main() {
    int arr[5];

    cout << "Enter 5 elements:" << endl;
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];

    cout << "Original Array: ";
    printArray(arr);

   
    opt(arr);

    cout << "Sorted Array: ";
    printArray(arr);

    return  0;
}


