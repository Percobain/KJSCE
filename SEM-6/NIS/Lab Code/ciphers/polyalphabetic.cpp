// Polyalphabetic (Vigenère) Cipher implementation in C++

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string encrypt(const string &text, const string &key) {
    string result;
    result.reserve(text.size());

    string keyUpper;
    keyUpper.reserve(key.size());
    for (char ch : key) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            keyUpper.push_back(static_cast<char>(toupper(static_cast<unsigned char>(ch))));
        }
    }

    if (keyUpper.empty()) {
        return text;
    }

    int keyIndex = 0;
    int keyLen = static_cast<int>(keyUpper.length());

    for (char ch : text) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            char base = isupper(static_cast<unsigned char>(ch)) ? 'A' : 'a';
            int p = ch - base;
            int k = keyUpper[keyIndex % keyLen] - 'A';
            char c = static_cast<char>((p + k) % 26 + base);
            result.push_back(c);
            keyIndex++;
        } else {
            result.push_back(ch);
        }
    }

    return result;
}

string decrypt(const string &text, const string &key) {
    string result;
    result.reserve(text.size());

    string keyUpper;
    keyUpper.reserve(key.size());
    for (char ch : key) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            keyUpper.push_back(static_cast<char>(toupper(static_cast<unsigned char>(ch))));
        }
    }

    if (keyUpper.empty()) {
        return text;
    }

    int keyIndex = 0;
    int keyLen = static_cast<int>(keyUpper.length());

    for (char ch : text) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            char base = isupper(static_cast<unsigned char>(ch)) ? 'A' : 'a';
            int c = ch - base;
            int k = keyUpper[keyIndex % keyLen] - 'A';
            char p = static_cast<char>((c - k + 26) % 26 + base);
            result.push_back(p);
            keyIndex++;
        } else {
            result.push_back(ch);
        }
    }

    return result;
}

int main() {
    string text, key;

    cout << "Enter plaintext : ";
    getline(cin, text);

    cout << "Enter key       : ";
    getline(cin, key);

    string encrypted = encrypt(text, key);
    cout << "Encrypted Text  : " << encrypted << endl;

    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted Text  : " << decrypted << endl;

    return 0;
}