// polimorphism in c++
// polymorphism is a greek word which means many forms.
// in c++ polymorphism is a feature which allows us to perform a single action in different ways.
// most common use of polymorphism is when a parent class reference is used to refer to a child class object.

// there are two types of polymorphism in c++. compile time polymorphism and runtime polymorphism. (will cover later)
// compile time polymorphism is achieved by function overloading and operator overloading.
// runtime polymorphism is achieved by function overriding.


#include <iostream>

class AbstractEmployee
{
    virtual void askForPromotion() = 0;
};

class Employee : AbstractEmployee
{
private:
    int age;

    std::string company;

protected:
    std::string name;

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
    void askForPromotion()
    {
        if (age > 30)
            std::cout << name << " got promoted\n";
        else
            std::cout << name << " did not get promoted\n";
    }
    virtual void work()
    {
        std::cout << name << " is working at Higher Level" << std::endl;
    }
};

class Developer : public Employee
{
public:
    std::string favProgrammingLanguage;
    // Note: if we don't define the constructor of the derived class, we will get error as base class already have a own constructor.
    Developer(int age, std::string name, std::string company, std::string favProgrammingLanguage)
        : Employee(age, name, company) //  we don't need again implement the base class constructorn in the derived class
                                       //  simply call the base class constructor with the required arguments
    {
        this->favProgrammingLanguage = favProgrammingLanguage;
    }
    void fixBug()
    {
        // std::cout << getName() << " fixed bug using " << favProgrammingLanguage << '\n';
        // since name is protected, we can access it directly
        std::cout << name << " fixed bug using " << favProgrammingLanguage << '\n';
    }
    void work()
    {
        std::cout << name << " is working at Developer Level" << std::endl;
    }
};

class Teacher : public Employee
{
public:
    std::string subject;
    Teacher(int age, std::string name, std::string company, std::string subject)
        : Employee(age, name, company)
    {
        this->subject = subject;
    }
    void prepareLesson()
    {
        std::cout << name << " is preparing " << subject << " lesson\n";
    }
    void work()
    {
        std::cout << name << " is working at Teacher Level" << std::endl;
    }
};

int main()
{
    Developer d = Developer(25, "Alex", "Google", "C++");
    Teacher t = Teacher(35, "Jack", "Google", "History");
    d.work();
    t.work();
    Employee *e1 = &d;
    Employee *e2 = &t;
    std::cout <<"-------------------"<<std::endl;
    // now we can use the work function of the derived class using the base class pointer. (use virtual keyword in base class function)
    e1->work();
    e2->work();
    

    return 0;
}
