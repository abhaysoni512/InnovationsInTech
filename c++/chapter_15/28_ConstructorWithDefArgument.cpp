#include <iostream>

class Foo
{
private:
    int m_x{};
    int m_y{};

public:
    Foo() // default constructor
    {
        std::cout << "Foo constructed\n";
    }

    Foo(int x, int y) // non-default constructor
        : m_x{x}, m_y{y}
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
    }
};

int main()
{
    Foo foo1{};     // Calls Foo() constructor
    Foo foo2{6, 7}; // Calls Foo(int, int) constructor

    return 0;
}

// important: The default constructor Foo() is called when no arguments are provided.
// The non-default constructor Foo(int, int) is called when two integer arguments are provided.
// This demonstrates how constructors can be overloaded based on the number and type of arguments.
// The default constructor is useful for creating objects with default values, while the non-default constructor allows for more flexibility in object initialization.

/*
    When you define a constructor like this:

    Foo(int x = 0, int y = 0)
    : m_x{x}, m_y{y}
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
    }

    it can act as both a default constructor (when no arguments are provided)
    and a non-default constructor (when arguments are provided).
     If you also have an explicitly defined default constructor, like this:

    Foo() // default constructor
    {
        std::cout << "Foo constructed\n";
    }
    then calling Foo foo1{}; becomes ambiguous. The compiler cannot determine whether to use the explicitly defined default constructor
    or the constructor with default arguments because both match a call with no arguments. This ambiguity causes a compilation error.
    In summary, having both a default constructor and a constructor with all parameters having default values leads to an ambiguous call 
    when no arguments are provided. To resolve this, you should choose one method for default construction
    rather than providing two constructors that can both serve that role.




*/