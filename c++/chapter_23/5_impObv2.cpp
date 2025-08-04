#include <iostream>
#include <string_view>

class A
{
public:
    virtual std::string_view getName() const { return "A"; }
};

class B : public A
{
public:
    // note: no virtual keyword in B, C, and D
    std::string_view getName() const { return "B"; }
};

class C : public B
{
public:
    std::string_view getName() const { return "C"; }
};

class D : public C
{
public:
    std::string_view getName() const { return "D"; }
};

int main()
{
    C c{};
    B &rBase{c}; // note: rBase is a B this time
    std::cout << rBase.getName() << '\n';

    return 0;
}

/*
In C++, once a method is declared virtual in the base class, it remains virtual throughout the inheritance chain, even if derived classes don't explicitly write virtual.

So getName() in B, C, and D all override A::getName() even though they don’t say virtual.


*/