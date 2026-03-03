#include <iostream>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
            unsigned char *iv, unsigned char *ciphertext){
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;
    
    // Create and initialize the context
    if(!(ctx = EVP_CIPHER_CTX_new())) {
        cerr << "Failed to create context" << endl;
        return -1;
    }
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        cerr << "EncryptInit failed" << endl;
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) {
        cerr << "EncryptUpdate failed" << endl;
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }
    ciphertext_len = len;
    
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
        cerr << "EncryptFinal failed" << endl;
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return ciphertext_len;
}

// decrypt function should be similar and we are using symmetric encryption so we will call encrypt again
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
            unsigned char *iv, unsigned char *plaintext){
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;
    
    // Create and initialize the context
    if(!(ctx = EVP_CIPHER_CTX_new())) {
        cerr << "Failed to create context" << endl;
        return -1;
    }
    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        cerr << "DecryptInit failed" << endl;
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }
    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) {
        cerr << "DecryptUpdate failed" << endl;
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }
    plaintext_len = len;
    
    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) {
        cerr << "DecryptFinal failed" << endl;
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }
    plaintext_len += len;
    
    EVP_CIPHER_CTX_free(ctx);
    return plaintext_len;
}

int main(){
    // step 1: generate key and iv

    unsigned char key[32]; // AES-256
    if(!RAND_bytes(key, sizeof(key))){
        cerr << "Key generation failed" << endl;
        return 1;
    }

    // 128-bit IV (16 bytes for AES)
    unsigned char iv[16];
    if(!RAND_bytes(iv, sizeof(iv))){
        cerr << "IV generation failed" << endl;
        return 1;
    }

    string plaintext = "This is a secret message that needs to be encrypted.";

    // step 2: encrypt
    unsigned char ciphertext[128];

    int ciphertext_len = encrypt((unsigned char*)plaintext.c_str(), plaintext.length(), key, iv, ciphertext);
    if(ciphertext_len == -1){
        cerr << "Encryption failed" << endl;
        return 1;
    }
    cout << "Ciphertext (hex): ";
    for(int i = 0; i < ciphertext_len; i++){
        cout << hex << setw(2) << setfill('0') << (int)ciphertext[i];
    }
    cout << endl;

    // step 3: decrypt
    unsigned char decryptedtext[128];
    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);
    if(decryptedtext_len == -1){
        cerr << "Decryption failed" << endl;
        return 1;
    }

    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the string
    cout << "Decrypted text: " << decryptedtext << endl;
    return 0;

}