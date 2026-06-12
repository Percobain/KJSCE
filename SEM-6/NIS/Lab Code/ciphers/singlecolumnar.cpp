#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <limits>

using namespace std;

string normalizeText(const string &text) {
    string res;
    for (char ch : text) {
        if (ch != ' ') {
            res.push_back(static_cast<char>(toupper(static_cast<unsigned char>(ch))));
        }
    }
    return res;
}

vector<int> getKeyOrder(const string &key) {
    int cols = static_cast<int>(key.size());
    vector<int> order(cols);
    for (int i = 0; i < cols; ++i) order[i] = i;

    sort(order.begin(), order.end(),
         [&key](int a, int b) {
             if (key[a] == key[b]) return a < b;
             return key[a] < key[b];
         });
    return order;
}

string encryptWithKey(const string &plain, const string &keyInput) {
    string text = normalizeText(plain);
    string key;
    key.reserve(keyInput.size());
    for (char ch : keyInput) {
        key.push_back(static_cast<char>(toupper(static_cast<unsigned char>(ch))));
    }

    int cols = static_cast<int>(key.size());
    if (cols == 0 || text.empty()) return "";

    int rows = (text.size() + cols - 1) / cols;
    vector<vector<char>> matrix(rows, vector<char>(cols, 'X'));

    int index = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (index < static_cast<int>(text.size())) {
                matrix[i][j] = text[index++];
            }
        }
    }

    vector<int> order = getKeyOrder(key);

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
    string text = normalizeText(plain);
    if (cols <= 0 || text.empty()) return "";

    int rows = (text.size() + cols - 1) / cols;
    vector<vector<char>> matrix(rows, vector<char>(cols, 'X'));

    int index = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (index < static_cast<int>(text.size())) {
                matrix[i][j] = text[index++];
            }
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

string decryptWithKey(const string &cipher, const string &keyInput) {
    if (cipher.empty()) return "";

    string key;
    key.reserve(keyInput.size());
    for (char ch : keyInput) {
        key.push_back(static_cast<char>(toupper(static_cast<unsigned char>(ch))));
    }

    int cols = static_cast<int>(key.size());
    if (cols == 0 || cipher.size() % cols != 0) return "";

    int rows = static_cast<int>(cipher.size()) / cols;
    vector<vector<char>> matrix(rows, vector<char>(cols, 'X'));

    vector<int> order = getKeyOrder(key);

    int index = 0;
    for (int colIdx : order) {
        for (int row = 0; row < rows; ++row) {
            matrix[row][colIdx] = cipher[index++];
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
    if (cipher.empty() || cols <= 0 || cipher.size() % cols != 0) return "";

    int rows = static_cast<int>(cipher.size()) / cols;
    vector<vector<char>> matrix(rows, vector<char>(cols, 'X'));

    int index = 0;
    for (int col = 0; col < cols; ++col) {
        for (int row = 0; row < rows; ++row) {
            matrix[row][col] = cipher[index++];
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
    cout << "Enter choice:\n";
    cout << "1. Encrypt with key (and decrypt)\n";
    cout << "2. Encrypt keyless (and decrypt)\n";
    cout << "Enter option: ";
    if (!(cin >> choice)) {
        return 0;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
        case 1: {
            cout << "Keyed Columnar Transposition\n";
            cout << "Enter message: ";
            string message;
            getline(cin, message);

            cout << "Enter key (word): ";
            string key;
            getline(cin, key);

            string encrypted = encryptWithKey(message, key);
            cout << "Encrypted message: " << encrypted << '\n';

            string decrypted = decryptWithKey(encrypted, key);
            cout << "Decrypted message: " << decrypted << '\n';
            break;
        }
        case 2: {
            cout << "Keyless Columnar Transposition\n";
            cout << "Enter message: ";
            string message;
            getline(cin, message);

            cout << "Enter number of columns: ";
            int cols;
            cin >> cols;

            string encrypted = encryptKeyless(message, cols);
            cout << "Encrypted message: " << encrypted << '\n';

            string decrypted = decryptKeyless(encrypted, cols);
            cout << "Decrypted message: " << decrypted << '\n';
            break;
        }
        default:
            cout << "Invalid choice.\n";
    }

    return 0;
}