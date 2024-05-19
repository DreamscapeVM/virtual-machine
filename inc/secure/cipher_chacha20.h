//
// Created by ChaCha on 2023-12-20.
//

#ifndef __INCLUDE_SECURE_CIPHER_CHACHA20_H
#define __INCLUDE_SECURE_CIPHER_CHACHA20_H
#include <secure/cipher.h>
#include <cstdint>
#include <array>


class cipher_chacha20 : public cipher {
public:
    cipher_chacha20(array<uint8_t, 32> key, array<uint8_t, 8> nonce);

    vector<uint8_t> encypt(const vector<uint8_t> &input) const override;
    vector<uint8_t> dencypt(const vector<uint8_t> &input) const override;
    string get_name() const override;

private:
    array<uint8_t, 32> key;
    array<uint8_t, 8> nonce;
};



#endif //CHACHA20_H
