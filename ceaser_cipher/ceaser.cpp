#include "ceaser.h"


Ceaser::Ceaser(int key) {
    m_key = key;
};

char Ceaser::shift_char(char c, int shift){
    if (!isalpha(c)) {
        return c; // do not shift non-alphabetic characters
    }
    char base = isupper(c) ? 'A' : 'a'; 
    return ((c - base + shift) % 26 + 26) % 26 + base;
};

std::string Ceaser::m_encrypt(std::string str) {
    std::string eString;
    for (char c : str) {
        eString += shift_char(c, m_key);
    }
    return eString;

};

std::string Ceaser::m_decrypt(std::string str) {
    std::string eString;
    for (char c : str) {
        eString += shift_char(c, -m_key);
    }
    return eString;

};



