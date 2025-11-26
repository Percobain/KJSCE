#include <bits/stdc++.h>
using namespace std;

vector<int> getNumericKey(string key) {
    int n = key.length();

    vector<pair<int, int>> key_order;
    for (int i = 0; i < n; ++i) {
        key_order.push_back({key[i], i});
    }

    sort(key_order.begin(), key_order.end());

    vector<int> numeric_key(n, 0);
    for (int i = 0; i < key_order.size(); ++i) {
        numeric_key[key_order[i].second] = i + 1;
    }

    return numeric_key;
}

string columnarEncrypt(string plaintext, string key) {
    
    plaintext.erase(remove(plaintext.begin(), plaintext.end(), ' '), plaintext.end());
    transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::toupper);
    transform(key.begin(), key.end(), key.begin(), ::toupper);

    int cols = key.length();
    int rows = ceil((double) plaintext.length() / cols);

    int padded_len = rows * cols;
    while (plaintext.length() < padded_len) plaintext += 'X';
    
    vector<vector<char>> matrix(rows, vector<char>(cols));
    int k = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = plaintext[k++];
        }
    }

    vector<int> numeric_key = getNumericKey(key);

    unordered_map<int, int> order_to_col;
    for (int i = 0; i < numeric_key.size(); ++i) {
        order_to_col[numeric_key[i]] = i;
    }

    string ciphertext = "";
    for (int num = 1; num <= cols; num++) {
        int col = order_to_col[num];
        for (int row = 0; row < rows; row++) {
            ciphertext += matrix[row][col];
        }
    }

    return ciphertext;
}

int main() {
    string key, plaintext;
    cout << "Enter the key: ";
    getline(cin, key);
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    string ciphertext = columnarEncrypt(plaintext, key);
    cout << "Encrypted Ciphertext: " << ciphertext << endl;

    return 0;
}