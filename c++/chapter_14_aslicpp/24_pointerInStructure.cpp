#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

int main()
{
    Employee joe{1, 34, 65000.0};

    ++joe.age;
    joe.wage = 68000.0;

    Employee *ptr{&joe};
    std::cout << ptr->id << '\n'; 
    std::cout << ptr->age << '\n';
    std::cout << ptr->wage << '\n';

    return 0;
}