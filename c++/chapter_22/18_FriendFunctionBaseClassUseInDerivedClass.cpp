/*
There’s one bit of trickiness that we can run into when trying to call friend functions in base classes, such as operator<<. Because friend functions of the base class aren’t actually part of the base class, using the scope resolution qualifier won’t work. Instead, we need a way to make our Derived class temporarily look like the Base class so that the right version of the function can be called.

use static_cast<const Base&>
*/

#include <iostream>

class Base
{
public:
    Base() {}

    friend std::ostream &operator<<(std::ostream &out, const Base &)
    {
        out << "In Base\n";
        return out;
    }
};

class Derived : public Base
{
public:
    Derived() {}

    friend std::ostream &operator<<(std::ostream &out, const Derived &d)
    {
        out << "In Derived\n";
        // static_cast Derived to a Base object, so we call the right version of operator<<
        out << static_cast<const Base &>(d);
        return out;
    }
};

int main()
{
    Derived derived{};

    std::cout << derived << '\n';

    return 0;
}