/*
In C++, it is not possible to remove or restrict functionality from a base class other than by modifying the source code. However, in a derived class, it is possible to hide functionality that exists in the base class, so that it can not be accessed through the derived class. This can be done simply by changing the relevant access specifier.


*/

#include <iostream>

class Base
{
public:
    int m_value{};
};

class Derived : public Base
{
private:
    using Base::m_value;

public:
    Derived(int value) : Base{value}
    {
    }
};

int main()
{
    Derived derived{7};
    //std::cout << derived.m_value; // error: m_value is private in Derived

    Base &base{derived};
    std::cout << base.m_value; // okay: m_value is public in Base

    return 0;
}