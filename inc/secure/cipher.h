//
// Created by ChaCha on 2023-12-20.
//

#ifndef __INCLUDE_SECURE_CIPHER_H
#define __INCLUDE_SECURE_CIPHER_H
#include <vector>
#include <string>

using namespace std;

class cipher {
public:
	virtual vector<uint8_t> encypt(const vector<uint8_t>& input) const = 0;
	virtual vector<uint8_t> dencypt(const vector<uint8_t>& input) const = 0;
	virtual string get_name() const = 0;
};

#endif //CHIPER_H
