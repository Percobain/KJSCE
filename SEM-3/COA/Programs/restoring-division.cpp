#include <bits/stdc++.h>
using namespace std;

void restoringDivision(int dividend, int divisor, int *quotient, int *remainder) {
    int acc = 0;
    int q = dividend;
    int n = sizeof(int) * 8;

    *quotient = 0;

    for (int i = 0; i < n; ++i) {
        acc = (acc << 1 | (q >> (n - 1) & 1));
        q <<= 1;

        acc -= divisor;

        if (acc < 0) {
            acc += divisor;
        } else {
            q |= 1;
        }
    }

    *quotient = q;
    *remainder = acc;
}

int main() {
    int dividend, divisor, quotient, remainder;
    cout << "Enter dividend: ";
    cin >> dividend;
    cout << "Enter divisor: ";
    cin >> divisor;

    if (divisor == 0) {
        cerr << "Error: Division by zero.\n";
        return 1;
    }

    restoringDivision(dividend, divisor, &quotient, &remainder);

    cout << "Quotient: " << quotient << '\n';
    cout << "Remainder: " << remainder << '\n';

    return 0;
}