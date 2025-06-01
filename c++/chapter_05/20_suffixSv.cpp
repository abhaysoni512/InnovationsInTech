#include <iostream>
#include <string>      // for std::string
#include <string_view> // for std::string_view

int main()
{
    using namespace std::string_literals;      // access the s suffix
    using namespace std::string_view_literals; // access the sv suffix
    
    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "goo\n"s;  // s suffix is a std::string literal
    std::cout << "moo\n"sv; // sv suffix is a std::string_view literal

    std::string name;
    // std::cin.ignore();                 // consume newline character (if any)
    std::cout << "Enter your name: ";  // note: no std::ws here
    std::getline(std::cin >> std::ws, name);
    std::cout << name << std::endl;
    return 0;
}