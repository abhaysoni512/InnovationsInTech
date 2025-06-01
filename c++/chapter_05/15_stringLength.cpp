#include <iostream>
#include <string>
int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Length of characters: " << name.length() << std::endl;

    //note if we want to use name.length() value it will be return as unsigned int, so make sure to type static type cast

    //Alternately, c++ 20 use std::ssize(name)
    std::cout << "Length of characters: " << std::ssize(name) << std::endl;

    return 0;
}