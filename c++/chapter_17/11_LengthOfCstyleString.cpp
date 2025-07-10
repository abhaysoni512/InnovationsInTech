#include<iostream>
#include<cstring> // for std::strlen
int main() {
    char str[255]{"string"};                              // 6 characters + null terminator
    std::cout << "length = " << std::strlen(str) << '\n'; // prints length = 6

    char *ptr{str};
    std::cout << "length = " << std::strlen(ptr) << '\n'; // prints length = 6
}