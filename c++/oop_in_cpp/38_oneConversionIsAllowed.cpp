#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
    std::string m_name{};

public:
    Employee(std::string_view name)
        : m_name{name}
    {
    }

    const std::string &getName() const { return m_name; }
};

void printEmployee(Employee e) // has an Employee parameter
{
    std::cout << e.getName();
}

int main()
{
    //printEmployee("Joe"); // we're supplying an string literal argument
    // The above line will not compile because the compiler will try to convert the string literal to an Employee object
    // and it will not be able to do so because the constructor of Employee is not explicit
    
    using namespace std::literals;
    printEmployee("Joe"sv); // we're supplying an string literal argument
    return 0;
}