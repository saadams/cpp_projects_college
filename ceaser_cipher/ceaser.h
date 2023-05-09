#ifndef CEASER_H
#define CEASER_H
#include <string>

class Ceaser
{

public:
    Ceaser(int key);
    std::string m_encrypt(std::string str);

    std::string m_decrypt(std::string str);

private:
    int m_key; // priv key
    char shift_char(char c, int shift);
};

#endif