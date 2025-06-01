// Inheritance in C++
// Inheritance is the mechanism by which a new class inherits properties and behavior from an existing class.
// The existing class is called the base class, and the new class is called the derived class.
// Inheritance allows us to define a class in terms of another class, which makes it easier to create and maintain an application.
// The derived class inherits all the features from the base class and can have additional features of its own.
// Inheritance is a powerful feature of C++ that allows the creation of a new class that is based on an existing class.


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
};

class Developer : public Employee {
public:
    std::string favProgrammingLanguage;
    // Note: if we don't define the constructor of the derived class, we will get error as base class already have a own constructor.
    Developer(int age, std::string name, std::string company, std::string favProgrammingLanguage)
        : Employee(age, name, company)  //  we don't need again implement the base class constructorn in the derived class
                                        //  simply call the base class constructor with the required arguments
    {
        this->favProgrammingLanguage = favProgrammingLanguage;
    }
    void fixBug()
    {
        //std::cout << getName() << " fixed bug using " << favProgrammingLanguage << '\n';
        //since name is protected, we can access it directly
        std::cout << name << " fixed bug using " << favProgrammingLanguage << '\n';
    }
};

class Teacher : public Employee {
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
};

int main()
{  
    Developer d = Developer(25, "Alex", "Google", "C++");
    d.fixBug();
    //d.askForPromotion(); // we are getting error bcz mode of inheritance is private by default in derived class
                          // so we can change mode of inheritance to protected or public
    d.printDetails();

    return 0;
}
