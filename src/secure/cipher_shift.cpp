//
// Created by ChaCha on 2023-12-20.
//

#include <secure/cipher_shift.h>

vector<uint8_t> cipher_shift::encypt(const vector<uint8_t> &input) const {
    vector<uint8_t> output(input.size());

    for (int i = 0; i < input.size(); i++) {
        short t = (static_cast<int>(input[i]) + key + 256);
        output[i] = static_cast<uint8_t>(t);
    }
    return output;
}

vector<uint8_t> cipher_shift::dencypt(const vector<uint8_t> &input) const {
    vector<uint8_t> output(input.size());

    for (int i = 0; i < input.size(); i++) {
        short t = (static_cast<int>(input[i]) - key + 256);
        output[i] = static_cast<uint8_t>(t);
    }
    return output;
}

string cipher_shift::get_name() const {
    return "cipher_shift";
}
