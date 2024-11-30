#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int

void nonRestoringDivision(uint dividend, uint divisor, uint *quotient, uint* remainder) {
    uint acc = 0;
    uint q = dividend;
    uint n = sizeof(uint) * 8;

    for (int i = 0; i < n; ++i) {

        // Shift the acc left by 1 bit and add the most significant bit of q to the least significant bit of the accumulator
        // Shift q left by 1 bit 
        acc = (acc << 1) | ((q >> (n-1)) & 1);
        q <<= 1;

        // Subtract the divisor from the accumulator
        acc -= divisor;


        if (acc & (1 << (n-1))) { // Checks the MSB of acc
            acc += divisor; // if MSB is negative, add divisor back to acc
        } else {
            q |= 1; // set the LSB of the quotient to 1
        }
    }

    // store the final quotient and remainder
    *quotient = q;
    *remainder = acc;
}


int main() {
    uint dividend, divisor;
    uint quotient, remainder;
    cout << "Enter Dividend: ";
    cin >> dividend;
    cout << "Enter Divisor: ";
    cin >> divisor;

    if (divisor == 0) {
        cerr << "Error: Division by Zero.\n";
        return 1;
    }

    nonRestoringDivision(dividend, divisor, &quotient, &remainder);
    cout << "Quotient: " << quotient << '\n';
    cout << "Remainder: " << remainder << '\n';
}