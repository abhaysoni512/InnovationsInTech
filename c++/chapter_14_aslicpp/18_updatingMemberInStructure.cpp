#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

std::ostream &operator<<(std::ostream &out, const Employee &e)
{
    out << e.id << ' ' << e.age << ' ' << e.wage;
    return out;
}

int main()
{
    Employee joe{1, 32, 60000.0};
    joe = {joe.id, 33, 66000.0}; // Joe had a birthday and got a raise
    std::cout << joe << '\n';

    return 0;
}