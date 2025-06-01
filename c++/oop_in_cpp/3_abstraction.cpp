// Abstraction in c++ is the concept of hiding the implementation details from the user
// and only providing the necessary details to the user. 
// The user does not need to know how the function is implemented.
// virtaul functions are used to achieve abstraction in c++. 

#include <iostream>
// i am preparing contract for the class whoever signs this contract has to implement the functions in the contract.
// this is called pure virtual function.
class AbstractEmployee
{
    virtual void askForPromotion() = 0;
};
// now i am creating a class which is signing the contract of AbstractEmployee class.
// how can i sign the contract of AbstractEmployee class?
// i have to implement the function askForPromotion() in the derived class.

class Employee : AbstractEmployee
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
    void askForPromotion(){
        if(age>30) std::cout<<name<<" got promoted\n";
        else std::cout << name << " did not get promoted\n";
    }
};

int main()
{
    Employee emp1 = Employee(25, "Alex", "Google");
    emp1.printDetails();
    emp1.setAge(26);
    emp1.getAge();
    emp1.askForPromotion();
    return 0;
}
