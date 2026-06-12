#include <iostream>
#include <string>
#include <cctype>

using namespace std;
string encrypt(string text, int shift) {
string result = "";
shift = shift % 26;
for (char ch : text) {
if (isupper(ch)) {
char c = (ch - 'A' + shift) % 26 + 'A';
result += c;
}
else if (islower(ch)) {
char c = (ch - 'a' + shift) % 26 + 'a';
result += c;
}
else {
result += ch;
}
}
return result;
}
string decrypt(string text, int shift) {
return encrypt(text, 26 - (shift % 26));
}
int main() {
string text;
int shift;
cout << "Enter text to encrypt: ";
getline(cin, text);
cout << "Enter shift value: ";
cin >> shift;
string encryptedText = encrypt(text, shift);
cout << "Encrypted Text: " << encryptedText << endl;

string decryptedText = decrypt(encryptedText, shift);
cout << "Decrypted Text: " << decryptedText << endl;
return 0;
}