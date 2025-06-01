#include <string>
#include <iostream>
int main(){
    std::string name{"Abhay"};
    name = "Abhay Soni"; // direct copy is allowd as name is a object
    std::cout << name << std::endl;
}