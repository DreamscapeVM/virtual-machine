//
// Created by ChaCha on 2023-12-20.
//

#include <secure/cipher_xor.h>

vector<uint8_t> cipher_xor::encypt(const vector<uint8_t> &input) const {
    vector<uint8_t> output(input.size());

    for (int i = 0; i < input.size(); i++) {
        output[i] = (input[i] ^ key[i % key.size()]);
    }
    return output;
}

vector<uint8_t> cipher_xor::dencypt(const vector<uint8_t> &input) const {
    vector<uint8_t> output(input.size());

    for (int i = 0; i < input.size(); i++) {
        output[i] = input[i] ^ key[i % key.size()];
    }
    return output;
}

string cipher_xor::get_name() const {
    return "chiper_xor";
}
