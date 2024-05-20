//
// Created by ChaCha on 2023-12-20.

#ifndef __INCLUDE_SECURE_CIPHER_SUBSTITUTION_H
#define __INCLUDE_SECURE_CIPHER_SUBSTITUTION_H

#include <secure/cipher.h>

class cipher_shift : public cipher {
    int key;
public:
    cipher_shift(int key) : key(key){}
    vector<uint8_t> encypt(const vector<uint8_t> &input) const override;
    vector<uint8_t> dencypt(const vector<uint8_t> &input) const override;
    string get_name() const override;
};


#endif //SUBSTITUTION_CIPHER_H
