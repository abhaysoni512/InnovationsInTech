//The return type of a member function returning a reference 
//to a data member should match the data member’s type
// to avoid confusion and potential errors in the code.
// we use auto to deduce the return type of a member function

#include <iostream>
#include <string>

class Employee
{
    std::string m_name{}; // std::string

public:
    void setName(std::string_view name) { m_name = name; }
    const auto &getName() const { return m_name; } // uses `auto` to deduce return type from m_name
};

int main()
{
    Employee joe{}; // joe exists until end of function
    joe.setName("Joe");

    std::cout << joe.getName(); // returns joe.m_name by reference

    return 0;
}