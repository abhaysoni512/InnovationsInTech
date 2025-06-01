#include <iostream>

class Foo
{
private:
    int m_x{};
    int m_y{};

public:
    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
    }
    // Note: no constructors declared
};

int main()
{
    Foo foo{};
    foo.print(); // Calls the default constructor implicitly
    return 0;
}