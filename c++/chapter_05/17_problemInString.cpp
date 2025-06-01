#include <iostream>
#include <string>

void printString(std::string str) // str makes a copy of its initializer
{
    std::cout << str << '\n';
}

int main()
{
    std::string s{"Hello, world!"}; // s makes a copy of its initializer
    printString(s);

    return 0;
}

#if 0
    When s is initialized, the C-style string literal "Hello, world!" is copied into memory allocated for std::string s. 
    Unlike fundamental types, initializing and copying a std::string is slow.

    This example makes two copies of the C-style string “Hello, world!”: one when we initialize s in main(), and another when we initialize parameter str in printString(). 
    That’s a lot of needless copying just to print a string!
#endif