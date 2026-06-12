#include <iostream>
#include <string>
#include <vector>

std::string encryptRailFence(const std::string &text, int height) {
    if (height <= 1 || text.empty())
        return text;

    int column = static_cast<int>(text.length());
    std::vector<std::string> rail(height, std::string(column, '\n'));

    bool directionDown = false;
    int row = 0;

    for (int j = 0; j < column; ++j) {
        rail[row][j] = text[j];

        if (row == 0 || row == height - 1)
            directionDown = !directionDown;

        row += directionDown ? 1 : -1;
    }

    std::string encryptedText;
    encryptedText.reserve(column);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < column; ++j) {
            if (rail[i][j] != '\n')
                encryptedText += rail[i][j];
        }
    }

    return encryptedText;
}

std::string decryptRailFence(const std::string &encryptedText, int height) {
    if (height <= 1 || encryptedText.empty())
        return encryptedText;

    int column = static_cast<int>(encryptedText.length());
    std::vector<std::string> rail(height, std::string(column, '\n'));

    bool directionDown = false;
    int row = 0;

    // Mark the places where characters will go
    for (int j = 0; j < column; ++j) {
        rail[row][j] = '*';

        if (row == 0 || row == height - 1)
            directionDown = !directionDown;

        row += directionDown ? 1 : -1;
    }

    // Fill the marked places with the cipher text
    int index = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < column; ++j) {
            if (rail[i][j] == '*' && index < column) {
                rail[i][j] = encryptedText[index++];
            }
        }
    }

    // Read the message in zig-zag manner
    std::string decryptedText;
    decryptedText.reserve(column);

    directionDown = false;
    row = 0;

    for (int j = 0; j < column; ++j) {
        decryptedText += rail[row][j];

        if (row == 0 || row == height - 1)
            directionDown = !directionDown;

        row += directionDown ? 1 : -1;
    }

    return decryptedText;
}

int main() {
    std::string text;
    int height;

    std::cout << "Enter the text: ";
    std::getline(std::cin, text);

    std::cout << "Enter the height value: ";
    std::cin >> height;

    std::string encrypted = encryptRailFence(text, height);
    std::cout << "Encrypted text = " << encrypted << std::endl;

    std::string decrypted = decryptRailFence(encrypted, height);
    std::cout << "Decrypted text = " << decrypted << std::endl;

    return 0;
}