#include <iostream>
#include "ceaser.h"
using namespace std;

int main() {
    string plainText, encryptText;

    int shift;


    cout << "Enter plaintext: ";
    getline(cin, plainText);//getline allows for spaces.

    cout << "Enter shift: ";
    cin >> shift;

    Ceaser c(shift);
    
    
    encryptText = c.m_encrypt(plainText);
    cout << "Encrypting .... ... .. . " << endl;
    cout << "Encrypted text: " << endl;
    cout << "--------------------------- " << endl;
    std::cout << "\033[31m" << encryptText << std::endl;
    cout << "\033[37m" << "--------------------------- " << endl;
    cout << "Decrypting .... ... .. ." << endl;
    cout << "Decrypted text: " << endl;
    cout << "--------------------------- " << endl;
    std::cout << "\033[32m" << c.m_decrypt(encryptText) << std::endl;
    cout << "\033[37m" << "--------------------------- " << endl;

    return 0;
}
