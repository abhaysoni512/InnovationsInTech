/*
Note that when you redefine a function in the derived class, the derived function does not inherit the access specifier of the function with the same name in the base class. It uses whatever access specifier it is defined under in the derived class. Therefore, a function that is defined as private in the base class can be redefined as public in the derived class, or vice-versa!
*/

#include <iostream>

class Base
{
private:
    void print() const
    {
        std::cout << "Base";
    }
};

class Derived : public Base
{
public:
    void print() const
    {
        std::cout << "Derived ";
    }
};

int main()
{
    Derived derived{};
    derived.print(); // calls derived::print(), which is public
    return 0;
}