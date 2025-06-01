#include <iostream>

class Foo
{
private:
    int m_x{};
    int m_y{};

public:
    Foo() = default; // default constructor
    Foo(int x = 0 , int y =0) // non-default constructor
        : m_x{x}, m_y{y}
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
    }
};

int main()
{
    Foo foo{};
    return 0;
}