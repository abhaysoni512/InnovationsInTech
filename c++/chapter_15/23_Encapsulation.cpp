#include <iostream>
#include <string>

class Employee
{
    std::string m_name{"John"};

public:
    void setName(std::string_view name)
    {
        m_name = name;
    }

    // use std::string::front() to get first letter of `m_name`
    char firstInitial() const { 
        return m_name.front(); // returns first character of m_name
     }
     #if 0
     char experimental() const
     {
         m_name = "John"; // This is not allowed
            return m_name.front(); // returns first character of m_name
     }
        #endif

    void print() const
    {
        std::cout << "Employee " << m_name << " has first initial " << firstInitial() << '\n';
    }
};

int main()
{
    Employee e{}; // defaults to "John"
    e.setName("Mark");
    e.print();

    return 0;
}