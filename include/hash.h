#ifndef CHINESETAHIL_HASH_H
#define CHINESETAHIL_HASH_H
#include <openssl/sha.h>
#include <string>
#include <sstream>
#include <iomanip>
class CHash256 {
public:
    static std::string Compute(const std::string& input) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, input.c_str(), input.size());
        SHA256_Final(hash, &sha256);
        std::stringstream ss;
        for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }
        return ss.str();
    }
};
#endif
