//
// Created by ChaCha on 2023-12-20.
//

#ifndef __INCLUDE_SECURE_CIPHER_BASE64_H
#define __INCLUDE_SECURE_CIPHER_BASE64_H

#include <secure/cipher.h>

class cipher_base64 : public cipher {
private:
    const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

public:
    cipher_base64() {}
    vector<uint8_t> encypt(const vector<uint8_t> &input) const override;
    vector<uint8_t> dencypt(const vector<uint8_t> &input) const override;
    string get_name() const override;
};



#endif //CIPHER_BASE64_H
