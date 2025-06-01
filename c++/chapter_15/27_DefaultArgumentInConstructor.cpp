#include <iostream>

class Foo
{
private:
    int m_x{};
    int m_y{};

public:
    Foo(int x = 0, int y = 0) // has default arguments
        : m_x{x}, m_y{y}
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
    }

};

int main()
{
    Foo foo1{};     // calls Foo(int, int) constructor using default arguments
    Foo foo2{6, 7}; // calls Foo(int, int) constructor
    Foo foo3{8};    // calls Foo(int, int) constructor using 8 & default arguments(0)

    return 0;
}