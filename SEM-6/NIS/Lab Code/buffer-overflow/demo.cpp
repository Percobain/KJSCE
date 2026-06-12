#include <iostream>
#include <cstring>
#include <climits>
#include <windows.h>

using namespace std;

/*
===========================================================
1. BUFFER OVERFLOW DEMONSTRATION
===========================================================
*/

void bufferOverflowDemo() {
    cout << "\n================ BUFFER OVERFLOW DEMO ================\n";

    char buffer[10];

    const char* safeInput = "Hello";
    const char* overflowInput = "ThisStringIsWayTooLongForBuffer";

    cout << "\nSafe Input Test:\n";
    strcpy(buffer, safeInput);
    cout << "Buffer content: " << buffer << endl;

    cout << "\nOverflow Input Test (Intentional Vulnerability):\n";
    cout << "Copying: " << overflowInput << endl;

    // Vulnerable code
    strcpy(buffer, overflowInput);  // Causes overflow

    cout << "Buffer after overflow: " << buffer << endl;
    cout << "NOTE: This may corrupt memory or behave unpredictably.\n";
}

/*
===========================================================
2. INTEGER OVERFLOW DEMONSTRATION
===========================================================
*/

void integerOverflowDemo() {
    cout << "\n================ INTEGER OVERFLOW DEMO ================\n";

    int maxInt = INT_MAX;
    cout << "INT_MAX = " << maxInt << endl;

    int overflowed = maxInt + 1;  // Signed overflow
    cout << "After INT_MAX + 1: " << overflowed << endl;

    cout << "\nUnsigned Integer Example:\n";
    unsigned int maxUnsigned = UINT_MAX;
    cout << "UINT_MAX = " << maxUnsigned << endl;

    unsigned int wrapped = maxUnsigned + 1;
    cout << "After UINT_MAX + 1: " << wrapped << endl;
}

/*
===========================================================
3. NULL TERMINATED STRING ISSUE DEMONSTRATION
===========================================================
*/

void nullTerminatedStringDemo() {
    cout << "\n================ NULL TERMINATED STRING DEMO ================\n";

    char str[5] = {'H', 'e', 'l', 'l', 'o'};  // No '\0'

    cout << "\nPrinting non-null terminated string:\n";
    cout << str << endl;  // Undefined behavior

    cout << "\nCorrect Version:\n";
    char correctStr[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    cout << correctStr << endl;
}

/*
===========================================================
4. RACE CONDITION DEMONSTRATION (Windows Threads)
===========================================================
*/

volatile int sharedCounter = 0;

DWORD WINAPI incrementCounter(LPVOID param) {
    int times = *(int*)param;

    for (int i = 0; i < times; i++) {
        sharedCounter++;  // Not thread-safe
    }

    return 0;
}

void raceConditionDemo() {
    cout << "\n================ RACE CONDITION DEMO ================\n";

    sharedCounter = 0;
    int increments = 1000000;

    HANDLE thread1 = CreateThread(NULL, 0, incrementCounter, &increments, 0, NULL);
    HANDLE thread2 = CreateThread(NULL, 0, incrementCounter, &increments, 0, NULL);

    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);

    cout << "Expected Counter: " << increments * 2 << endl;
    cout << "Actual Counter:   " << sharedCounter << endl;

    cout << "\nIf actual value is less than expected → Race Condition occurred.\n";

    CloseHandle(thread1);
    CloseHandle(thread2);
}

/*
===========================================================
MAIN FUNCTION
===========================================================
*/

int main() {
    cout << "========== SECURITY VULNERABILITY DEMONSTRATIONS ==========\n";

    // bufferOverflowDemo();
    integerOverflowDemo();
    nullTerminatedStringDemo();
    raceConditionDemo();

    cout << "\n================ END OF DEMO ================\n";

    return 0;
}