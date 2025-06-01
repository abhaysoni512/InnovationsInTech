#include <iostream>

template <typename T>
class Calculator
{
public:
    T add(T a, T b)
    {
        return a + b;
    }
    T subtract(T a, T b)
    {
        return a - b;
    }
    T multiply(T a, T b)
    {
        return a * b;
    }
    T divide(T a, T b)
    {
        return a / b;
    }
};
int main()
{
    Calculator<int> intCalc;
    Calculator<float> floatCalc;
    std::cout << intCalc.add(5, 6) << std::endl;
    std::cout << floatCalc.add(5.5, 6.6) << std::endl;

    std::cout << intCalc.subtract(5, 6) << std::endl;
    return 0;
}