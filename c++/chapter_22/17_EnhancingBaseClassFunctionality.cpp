/*
Sometimes we don’t want to completely replace a base class function, but instead want to add additional functionality to it when called with a derived object. In the above example, note that Derived::identify() completely hides Base::identify()! This may not be what we want. It is possible to have our derived function call the base version of the function of the same name (in order to reuse code) and then add additional functionality to it.
*/

#include <iostream>

class Base
{
public:
    Base() {}

    void identify() const { std::cout << "Base::identify()\n"; }
};

class Derived : public Base
{
public:
    Derived() {}

    void identify() const
    {
        std::cout << "Derived::identify()\n";
        Base::identify(); // note call to Base::identify() here
    }
};

int main()
{
    Base base{};
    base.identify();

    Derived derived{};
    derived.identify();

    return 0;
}