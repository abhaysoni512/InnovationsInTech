// Encapsulation in C++
// Encapsulation is the bundling of data and the methods that operate on that data into a single unit.
// Encapsulation is used to hide the values or state of a structured data object inside a class,
// preventing unauthorized parties' direct access to them.
// now to use these data we have to use the member functions of the class.
// getter and setter functions are used to access and modify the private data members of the class.

#include <iostream>

class Employee
{
private:
    int age;
    std::string name;
    std::string company;
public:
    void setAge(int age)
    {
        this->age = age;
    }
    void setName(std::string name)
    {
        this->name = name;
    }
    void setCompany(std::string company)
    {
        this->company = company;
    }
    int getAge()
    {
        return age;
    }
    std::string getName()
    {
        return name;
    }
    std::string getCompany()
    {
        return company;
    }
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
    Employee emp1 = Employee(25, "Alex", "Google");
    emp1.printDetails();
    emp1.setAge(26);
    emp1.getAge();
    return 0;
}