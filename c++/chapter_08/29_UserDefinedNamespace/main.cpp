#include <iostream>
#include "foo.h" // Include the header for Foo::doSomething
#include "goo.h" // Include the header for Goo::doSomething
int main()
{
    std::cout << Goo::doSomething(4, 3) << '\n'; // Calls Foo::doSomething
    return 0;
}