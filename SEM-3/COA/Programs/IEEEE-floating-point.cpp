#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define ull unsigned long long

typedef union {
    float f;
    struct {
        uint mantissa: 23;
        uint exponent: 8;
        uint sign: 1;
    } raw;
} myfloat32;

typedef union {
    double f;
    struct {
        ull mantissa: 52;
        uint exponent: 11;
        uint sign: 1;
    } raw;
} myfloat64;

void printBinary(int n) {
    bitset<32> b(n);
    cout << b.to_string() << '\n';
}

void printBinary64(ull n) {
    bitset<64> b(n);
    cout << b.to_string() << '\n';
}

void printIEEE32(myfloat32 var) {
    cout << "Sign: " << var.raw.sign << '\n';
    cout << "Exponent: ";
    printBinary(var.raw.exponent);
    cout << "Mantissa: ";
    printBinary(var.raw.mantissa);
    cout << '\n';
}

void printIEEE64(myfloat64 var) {
    cout << "Sign: " << var.raw.sign << '\n';
    cout << "Exponent: ";
    printBinary(var.raw.exponent);
    cout << "Mantissa: ";
    printBinary64(var.raw.mantissa);
    cout << '\n';
}


// void decimalToBinary(int n) { 
//     if (n == 0) {
//         return;
//     }
//     decimalToBinary(n / 2);
//     cout << n % 2;
// }

void decimalToBinary(float num) {
    myfloat32 var;
    var.f = num;
    printBinary(var.raw.mantissa);
    cout << endl;
}

int main() {
    float num;
    cout << "Enter a Number: ";
    cin >> num;
    decimalToBinary(num);
    return 0;
}   

// int main() {
//     int choice;
//     cout << "Enter 1 for 32-bit IEEE 754 or 2 for 64-bit IEEE 754: ";
//     cin >> choice;
//     if (choice == 1) {
//         myfloat32 var;
//         cout << "Enter a decimal number: ";
//         cin >> var.f;
//         printIEEE32(var);
//     } else if (choice == 2) {
//         myfloat64 var;
//         cout << "Enter a decimal number: ";
//         cin >> var.f;
//         printIEEE64(var);
//     } else {
//         cout << "Invalid choice.\n";
//     }

//     return 0;
// }

// sign: 0->positive, 1->negative
// exponent: 127 for 32-bit, 1023 for 64-bit
// mantissa: 23 bits for 32-bit, 52 bits for 64-bit

// example for 32-bit IEEE 754
// Q) convert 12.5 to IEEE 754
// 12.5 = 1100.1 
// 12.5 = 1.1001 * 2^3 = 1.1001, 2^3 because 3 bits are shifted to the left
//  (mantissa) * 2^3 (exponent)
// exponent = 3
// mantissa = 1001
// exponent + 127 = 3 + 127 = 130 = 10000010
// mantissa = 1001 = 10010000000000000000000 (23 bits) (add 19 0s to the right)

// 12.5 = 0 10000010 10010000000000000000000 (32 bits)

// example for 64-bit IEEE 754
// Q) convert 12.5 to IEEE 754
// 12.5 = 1100.1
// 12.5 = 1.1001 * 2^3 = 1.1001, 2^3 because 3 bits are shifted to the left
//  (mantissa) * 2^3 (exponent)
// exponent = 3
// mantissa = 1001
// exponent + 1023 = 3 + 1023 = 1026 = 10000000010
// mantissa = 1001 = 1001000000000000000000000000000000000000000000000000 (52 bits) (add 48 0s to the right)
// 12.5 = 0 10000000010 1001000000000000000000000000000000000000000000000000 (64 bits)  