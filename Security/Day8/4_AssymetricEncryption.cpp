/*
Asymmetric encryption uses a public-private key pair: encrypt with public key, decrypt with private. RSA is a common algorithm based on prime factorization. Below, I'll provide a complete C++ demo using OpenSSL for RSA-2048 (secure key size). It generates keys, encrypts a message with the public key, and decrypts with the private key.

*/
#include <iostream>
#include <string>
#include <cstring>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/rand.h>

using namespace std;

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

RSA* generateRSAKeyPair(int bits) {
    RSA *rsa = RSA_new();
    BIGNUM *e = BN_new();
    BN_set_word(e, RSA_F4);  // Common public exponent: 65537

    if (!RSA_generate_key_ex(rsa, bits, e, NULL)) {
        handleErrors();
    }

    BN_free(e);
    return rsa;
}

int publicKeyEncrypt(RSA* rsa, const unsigned char* plaintext, int plaintext_len, unsigned char* ciphertext) {
    int result = RSA_public_encrypt(plaintext_len, plaintext, ciphertext, rsa, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) {
        handleErrors();
    }
    return result;
}

int privateKeyDecrypt(RSA* rsa, const unsigned char* ciphertext, int ciphertext_len, unsigned char* plaintext) {
    int result = RSA_private_decrypt(ciphertext_len, ciphertext, plaintext, rsa, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) {
        handleErrors();
    }
    return result;
}

int main(){
    // seed the random number generator
    if(!RAND_poll()){
        cerr << "RAND_poll failed" << endl;
        return 1;
    }

    // step 1: generate RSA key pair
    int bits = 2048;
    RSA* rsaKeyPair = generateRSAKeyPair(bits);
    if(!rsaKeyPair){
        cerr << "Key pair generation failed" << endl;
        return 1;
    }

    string plaintext = "This is a secret message to be encrypted using RSA.";

    unsigned char encrypted[512]; // RSA size for 2048 bits
    unsigned char decrypted[512];

    // step 2: encrypt with public key
    int encrypted_length = publicKeyEncrypt(rsaKeyPair, (unsigned char*)plaintext.c_str(), plaintext.length(), encrypted);
    cout << "Encrypted message length: " << encrypted_length << " bytes" << endl;

    // step 3: decrypt with private key
    int decrypted_length = privateKeyDecrypt(rsaKeyPair, encrypted, encrypted_length, decrypted);
    decrypted[decrypted_length] = '\0'; // Null-terminate the decrypted string  
    cout << "Decrypted message: " << decrypted << endl;
    // cleanup (donot use RSA_FREE as it is deprecated)
    RSA_free(rsaKeyPair);
    return 0;

}