#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <openssl/evp.h>

std::string sha1_openssl3(const std::string& input) {
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    const EVP_MD* md = EVP_get_digestbyname("SHA1");
    
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int length = 0;

    // 1. Initialize the context with the SHA1 algorithm
    EVP_DigestInit_ex(context, md, nullptr);

    // 2. Feed the data
    EVP_DigestUpdate(context, input.c_str(), input.length());

    // 3. Finalize the hash
    EVP_DigestFinal_ex(context, hash, &length);

    // Clean up
    EVP_MD_CTX_free(context);

    // Convert bytes to hex string
    std::stringstream ss;
    for (unsigned int i = 0; i < length; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }

    return ss.str();
}

int main() {
    std::string text = "GeeksForGeeks";
    std::cout << "Input: " << text << std::endl;
    std::cout << "SHA-1: " << sha1_openssl3(text) << std::endl;

    return 0;
}