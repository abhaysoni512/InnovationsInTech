#include <iostream>
#include <string>

int main(){
    // auto keyword is used to deduce the type of variable at compile time based on its initializer
    auto x = 5;
    auto y = 5.5;
    auto z = "Hello";
    auto u {5};   // this is valid after c++14
    std::cout<<x<<std::endl;
    std::cout<<y<<std::endl;
    std::cout<<z<<std::endl;
    std::cout<<u<<std::endl;
    return 0;
}