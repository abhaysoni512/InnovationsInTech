#include <iostream>
#include <iomanip>
#include <openssl/evp.h>
#include <cstring>

int main(){
    std::string inputstring = "This is a message sent by a computer user.";
    // encoding the message using the library function
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len;
    EVP_Digest(inputstring.c_str(), inputstring.length(), digest, &digest_len, EVP_md5(), NULL);
    // print the encoded message in hexadecimal format
    std::cout << "MD5 Digest: ";
    for(unsigned int i = 0; i < digest_len; i++){
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)digest[i];
    }
    std::cout << std::endl;
    return 0;

}