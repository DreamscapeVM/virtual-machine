//
// Created by ChaCha on 2023-12-20.
//

#ifndef __INCLUDE_SECURE_CIPHER_VIGENERE_H
#define __INCLUDE_SECURE_CIPHER_VIGENERE_H

#include <secure/cipher.h>

class cipher_vigenere : public cipher {
    vector<uint8_t> key;

public:
    cipher_vigenere(const vector<uint8_t>& key) : key(key){}
    vector<uint8_t> encypt(const vector<uint8_t> &input) const override;
    vector<uint8_t> dencypt(const vector<uint8_t> &input) const override;
    string get_name() const override;
};




#endif //CIPHER_VIGENERE_H
