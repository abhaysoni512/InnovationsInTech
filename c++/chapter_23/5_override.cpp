#include <iostream>
#include <string_view>

class A
{
public:
    virtual std::string_view getName1(int x) { return "A"; }
    virtual std::string_view getName2(int x) { return "A"; }
};

class B : public A
{
public:
#if 0
    virtual std::string_view getName1(short x) { return "B"; }     // note: parameter is a short
    virtual std::string_view getName2(int x) const { return "B"; } // note: function is const
#endif
    // we will use override it tells compiler to override method if it don't get successfull it will throw error
    virtual std::string_view getName1(short x) override { return "B"; }     // note: parameter is a short
    virtual std::string_view getName2(int x) const override{ return "B"; } // note: function is const
   // If a member function is both const and an override, the const must be listed first.const override is correct, override const is not.
};

int main()
{
    B b{};
    A &rBase{b};
    std::cout << rBase.getName1(1) << '\n';
    std::cout << rBase.getName2(2) << '\n';

    return 0;
}

// this will print A ------> A which screw our override 