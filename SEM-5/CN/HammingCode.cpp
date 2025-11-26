#include <bits/stdc++.h>
using namespace std;

vector<int> generateHammingCode(vector<int> &data) {
    vector<int> arr(7);

    arr[2] = data[0];
    arr[4] = data[1];
    arr[5] = data[2];
    arr[6] = data[3];

    arr[0] = arr[2] ^ arr[4] ^ arr[6];
    arr[1] = arr[2] ^ arr[5] ^ arr[6];
    arr[2] = arr[4] ^ arr[5] ^ arr[6];

    return arr;
}

int detectAndCorrect(vector<int> &arr) {
    int p1 = arr[0] ^ arr[2] ^ arr[4] ^ arr[6];
    int p2 = arr[1] ^ arr[2] ^ arr[5] ^ arr[6];
    int p4 = arr[3] ^ arr[4] ^ arr[5] ^ arr[6];

    int err = p4 * 4 + p2 * 2 + p1 * 1;

    if (err != 0) {
        cout << "Error Detected at Position: " << err << '\n';
        arr[err - 1] ^= 1;
    } 
    else {
        cout << "No Error Detected" << '\n';
    }

    return err;
}

void printCode(vector<int>&code) {
    for (int b : code) cout << b << " ";
    cout << endl;
}


int main() {
    vector<int> data(4);
    cout << "Enter 4 data bits: ";
    for (int i = 0; i < 4; ++i) {
        cin >> data[i];
        if (data[i] != 0 && data[i] != 1) {
            cout << "Only 0/1 Bits allowed" << '\n';
            return 1;
        }
    }

    // Sender
    vector<int> arr = generateHammingCode(data);
    cout << "Hamming Code sent: ";
    printCode(arr);

    // Reciever
    cout << "Enter the 7-bit code: ";
    vector<int> rec(7);
    for (int i = 0; i < 7; ++i) cin >> rec[i];
    int err = detectAndCorrect(rec);
    cout << "Corrected Code: ";
    printCode(rec);

    cout << "Extracted data bits: ";
    cout << rec[2] << " " << rec[4] << " " << rec[5] << " " << rec[6] << '\n';

    return 0;

}