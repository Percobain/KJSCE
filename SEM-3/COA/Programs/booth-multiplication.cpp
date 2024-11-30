#include <bits/stdc++.h>
using namespace std;

void printBinary(int n, int size) {
    for (int i = size - 1; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
    cout << '\n';
}

// Function to perform arithmetic right shift
void arithmeticRightShift(int& A, int& Q, int& Q_1, int size) {
    Q_1 = Q & 1; // Store the least significant bit of Q
    Q = (Q >> 1) | ((A & 1) << (size - 1)); // Shift Q right by 1 and set the most significant bit to the least significant bit of A
    A = (A >> 1); // Shift A right by 1
}

int binaryAdd(int a, int b) {
    return a + b;
}

void boothAlgorithm(int M, int Q, int size) {
    int A = 0;
    int Q_1 = 0;
    int count = size;

    cout << "Initial values:" << '\n';
    cout << "A: ";
    printBinary(A, size);
    cout << "Q: ";
    printBinary(Q, size);
    cout << "Q-1: " << Q_1 << '\n';
    cout << "M: ";
    printBinary(M, size);
    cout << '\n';

    while (count > 0) {
        int Q0 = Q & 1;
        
        // Apply Booth's Algorithm
        if (Q0 == 1 && Q_1 == 0) {
            A = binaryAdd(A, -M);
            cout << "A = A - M" << '\n';
        } else if (Q0 == 0 && Q_1 == 1) {
            A = binaryAdd(A, M);
            cout << "A = A + M" << '\n';
        }

        // Arithmetic right shift
        arithmeticRightShift(A, Q, Q_1, size);

        cout << "After shift:  A: ";
        printBinary(A, size);
        cout << "Q: ";
        printBinary(Q, size);
        cout << "Q-1: " << Q_1 << '\n';
        cout << '\n';

        count--;
    }

    int result = (A << size) | Q;
    cout << "Final result: ";
    printBinary(result, size * 2);
    cout << "Decimal result: " << result << '\n';
}

int main() {
    int M, Q, size;

    cout << "Enter the bit size: ";
    cin >> size;

    cout << "Enter multiplicand (M) in decimal: ";
    cin >> M;

    cout << "Enter multiplier (Q) in decimal: ";
    cin >> Q;

    boothAlgorithm(M, Q, size);

    return 0;
}