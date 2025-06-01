/*
Finally, although it is not done very often, it is possible to overload a member function to 
have a const and non-const version of the same function. This works because the const qualifier
 is considered part of the function’s signature, 
so two functions which differ only in their const-ness are considered distinct.
*/

#include <iostream>

struct Something
{
    void print()
    {
        std::cout << "non-const\n";
    }

    void print() const
    {
        std::cout << "const\n";
    }
};

int main()
{
    Something s1{};
    s1.print(); // calls print()

    const Something s2{};
    s2.print(); // calls print() const

    return 0;
}