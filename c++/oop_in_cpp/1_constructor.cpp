#include <iostream>

class Employee
{
public:
    int age;
    std::string name;
    std::string company;

    Employee(int age, std::string name, std::string company)
    {
        this->age = age;
        this->name = name;
        this->company = company;
    }

    void printDetails()
    {
        std::cout << "Name: " << name << '\n';
        std::cout << "Age: " << age << '\n';
        std::cout << "Company: " << company << '\n';
    }


};

int main()
{
    Employee emp1= Employee(25, "Alex", "Google");
    emp1.printDetails();
    return 0;
}