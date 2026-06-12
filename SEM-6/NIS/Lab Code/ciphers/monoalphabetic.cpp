// Monoalphabetic substitution cipher in C++
// Uses a fixed key mapping for English alphabet

#include <iostream>
#include <string>

std::string encrypt(const std::string &text) {
    const std::string KEY = "QWERTYUIOPASDFGHJKLZXCVBNM"; // mapping for A-Z
    std::string result;
    result.reserve(text.size());

    for (char ch : text) {
        if (ch >= 'A' && ch <= 'Z') {
            result.push_back(KEY[ch - 'A']);
        } else if (ch >= 'a' && ch <= 'z') {
            char enc = KEY[ch - 'a'];                // encrypt as uppercase
            result.push_back(static_cast<char>(enc + ('a' - 'A'))); // to lowercase
        } else {
            result.push_back(ch); // non-alphabetic characters unchanged
        }
    }

    return result;
}

int main() {
    std::string text;

    std::cout << "Enter plaintext: ";
    std::getline(std::cin, text);

    std::string encrypted = encrypt(text);
    std::cout << "Encrypted text: " << encrypted << std::endl;

    return 0;
}