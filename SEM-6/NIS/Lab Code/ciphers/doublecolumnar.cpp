#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <limits>

using namespace std;

string normalize(const string &text) {
    string res;
    for (char c : text) {
        if (c != ' ')
            res.push_back(toupper(static_cast<unsigned char>(c)));
    }
    return res;
}

string encryptKeyed(const string &plain, const string &key) {
    string text = normalize(plain);
    string k;
    for (char c : key) k.push_back(toupper(static_cast<unsigned char>(c)));

    int cols = static_cast<int>(k.size());
    if (cols == 0 || text.empty()) return text;

    int rows = (text.size() + cols - 1) / cols;
    vector<string> matrix(rows, string(cols, 'X'));

    int idx = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (idx < static_cast<int>(text.size()))
                matrix[i][j] = text[idx++];
        }
    }

    vector<int> order(cols);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),
         [&](int a, int b) { return k[a] < k[b]; });

    string cipher;
    cipher.reserve(rows * cols);
    for (int col : order) {
        for (int row = 0; row < rows; ++row) {
            cipher.push_back(matrix[row][col]);
        }
    }
    return cipher;
}

string encryptKeyless(const string &plain, int cols) {
    string text = normalize(plain);
    if (cols <= 0 || text.empty()) return text;

    int rows = (text.size() + cols - 1) / cols;
    vector<string> matrix(rows, string(cols, 'X'));

    int idx = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (idx < static_cast<int>(text.size()))
                matrix[i][j] = text[idx++];
        }
    }

    string cipher;
    cipher.reserve(rows * cols);
    for (int col = 0; col < cols; ++col) {
        for (int row = 0; row < rows; ++row) {
            cipher.push_back(matrix[row][col]);
        }
    }
    return cipher;
}

string decryptKeyed(const string &cipher, const string &key) {
    if (cipher.empty()) return cipher;

    string k;
    for (char c : key) k.push_back(toupper(static_cast<unsigned char>(c)));

    int cols = static_cast<int>(k.size());
    if (cols == 0) return cipher;

    int rows = cipher.size() / cols;
    vector<string> matrix(rows, string(cols, 'X'));

    vector<int> order(cols);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),
         [&](int a, int b) { return k[a] < k[b]; });

    int idx = 0;
    for (int col : order) {
        for (int row = 0; row < rows; ++row) {
            matrix[row][col] = cipher[idx++];
        }
    }

    string plain;
    plain.reserve(rows * cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            plain.push_back(matrix[i][j]);
        }
    }

    while (!plain.empty() && plain.back() == 'X') {
        plain.pop_back();
    }
    return plain;
}

string decryptKeyless(const string &cipher, int cols) {
    if (cipher.empty() || cols <= 0) return cipher;

    int rows = cipher.size() / cols;
    vector<string> matrix(rows, string(cols, 'X'));

    int idx = 0;
    for (int col = 0; col < cols; ++col) {
        for (int row = 0; row < rows; ++row) {
            matrix[row][col] = cipher[idx++];
        }
    }

    string plain;
    plain.reserve(rows * cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            plain.push_back(matrix[i][j]);
        }
    }

    while (!plain.empty() && plain.back() == 'X') {
        plain.pop_back();
    }
    return plain;
}

int main() {
    int choice;
    cout << "Enter choice:\n1. Encrypt - Keyed (Double)\n2. Encrypt - Keyless (Double)\n";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
        case 1: {
            cout << "Keyed Columnar Transposition (Double)\n";
            cout << "Enter message: ";
            string message;
            getline(cin, message);

            cout << "Enter key (word 1): ";
            string k1;
            getline(cin, k1);

            cout << "Enter key (word 2): ";
            string k2;
            getline(cin, k2);

            string inter = encryptKeyed(message, k1);
            string encrypted = encryptKeyed(inter, k2);

            cout << "Encrypted message: " << encrypted << "\n";

            string decryptedOnce = decryptKeyed(encrypted, k2);
            string decryptedTwice = decryptKeyed(decryptedOnce, k1);

            cout << "Decrypted message: " << decryptedTwice << "\n";
            break;
        }
        case 2: {
            cout << "Keyless Columnar Transposition (Double)\n";
            cout << "Enter message: ";
            string message;
            getline(cin, message);

            cout << "Enter number of columns: ";
            int cols;
            cin >> cols;

            string inter = encryptKeyless(message, cols);
            string encrypted = encryptKeyless(inter, cols);

            cout << "Encrypted message: " << encrypted << "\n";

            string decryptedOnce = decryptKeyless(encrypted, cols);
            string decryptedTwice = decryptKeyless(decryptedOnce, cols);

            cout << "Decrypted message: " << decryptedTwice << "\n";
            break;
        }
        default:
            cout << "Invalid choice\n";
    }

    return 0;
}