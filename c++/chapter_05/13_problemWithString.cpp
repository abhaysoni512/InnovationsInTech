#include <iostream>
#include <string>

int main(){
    
    std::string name{};
    std::string color{};
    #if 0
    std::cout << "Enter your full name: ";
    std::cin >> name; // this won't work as expected since std::cin breaks on whitespace

    std::cout << "Enter your favorite color: ";
    
    std::cin >> color;
    #endif

    std::cout << "Enter your full name: ";
    std::getline(std::cin, name); // this will work as expected

    std::cout << "Enter your favorite color: ";
    std::getline(std::cin, color);
    std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';

    return 0;
}