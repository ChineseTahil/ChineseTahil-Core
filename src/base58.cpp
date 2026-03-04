#include <iostream>
#include <vector>
#include <algorithm>

const char* ALPHABET = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

std::string EncodeBase58(const std::vector<unsigned char>& input) {
    std::vector<unsigned char> digits(input.size() * 138 / 100 + 1, 0);
    for (unsigned char byte : input) {
        int carry = byte;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            carry += *it << 8;
            *it = carry % 58;
            carry /= 58;
        }
    }
    std::string res;
    auto it = std::find_if(digits.begin(), digits.end(), [](unsigned char d) { return d != 0; });
    while (it != digits.end()) res += ALPHABET[*it++];
    return res;
}
