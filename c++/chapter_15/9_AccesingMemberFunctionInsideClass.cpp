/*
With non-member functions, we have to explicitly pass an object to the function to work with,
 and members are explicitly accessed through that object.
With member functions, we implicitly pass an object to the function to work with, 
and members are implicitly accessed through that object.
*/
#include <iostream>
#include <string>

struct Person
{
    std::string name{};
    int age{};

    void kisses(const Person &person)
    {
        std::cout << name << " kisses " << person.name << '\n';
    }
};

int main()
{
    Person joe{"Joe", 29};
    Person kate{"Kate", 27};

    joe.kisses(kate);

    return 0;
}