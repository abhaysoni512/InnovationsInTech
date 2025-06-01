#include <iostream>
using namespace std;
class Calculator
{
private:
    int m_x{};

public:
    Calculator(int x) // constructor
        : m_x{x}
    {
    }
    // Function chaining
    Calculator &add(int y)
    {
        m_x += y;
        return *this;
    }
    Calculator &subtract(int y)
    {
        m_x -= y;
        return *this;
    }
    auto getResult() const
    {
        return m_x;
    }

    void reset()
    {
       *this = Calculator(0); // reset to default constructor
    }
};

int main()
{
    Calculator c(5);
    c.add(7).subtract(3);
    std::cout << c.getResult() << std::endl; // Output: 9
    return 0;
}