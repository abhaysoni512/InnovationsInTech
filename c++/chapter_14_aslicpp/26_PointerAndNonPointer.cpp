#include <iostream>

struct employee{
    int id{};
    int salary{};
};

struct company{
    std::string name{};
    employee emp{};
};

int main(){
    company c{"Google", {1, 10000}};
    company *ptr{&c};
    std::cout << ptr->name << '\n';
    std::cout << ptr->emp.id << '\n';
    std::cout << ptr->emp.salary << '\n';
    return 0;

}
