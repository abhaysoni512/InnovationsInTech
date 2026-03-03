#include <iostream>
#include <string>
#include <cstring>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

std::string base64Encode(const unsigned char* data, size_t len) {
    BIO *bio = BIO_new(BIO_f_base64());
    BIO *bmem = BIO_new(BIO_s_mem());
    bio = BIO_push(bio, bmem);
    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);  // No newlines

    BIO_write(bio, data, len);
    BIO_flush(bio);

    BUF_MEM *bufferPtr;
    BIO_get_mem_ptr(bio, &bufferPtr);
    std::string encoded(bufferPtr->data, bufferPtr->length);

    BIO_free_all(bio);
    return encoded;
}

std::string base64Decode(const std::string& encoded) {
    BIO *bio = BIO_new_mem_buf(encoded.c_str(), encoded.length());
    BIO *b64 = BIO_new(BIO_f_base64());
    bio = BIO_push(b64, bio);
    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);  // No newlines

    char buffer[encoded.length()];  // Sufficient size
    int decoded_len = BIO_read(bio, buffer, encoded.length());
    std::string decoded(buffer, decoded_len);

    BIO_free_all(bio);
    return decoded;
}

int main() {
    std::string data = "Hello, World!";
    std::string encoded = base64Encode(reinterpret_cast<const unsigned char*>(data.c_str()), data.length());
    std::cout << "Encoded: " << encoded << std::endl;

    std::string decoded = base64Decode(encoded);
    std::cout << "Decoded: " << decoded << std::endl;

    return 0;
}