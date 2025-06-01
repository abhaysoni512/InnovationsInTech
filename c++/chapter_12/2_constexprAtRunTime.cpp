#include <iostream>
// constexpr function that returns the greater of two integers
// note that the parameters are not constexpr
// this function can be called at compile-time or run-time depending on its arguments
// if called at run-time, it behaves like a regular function
// here, x and y are not constexpr so the function will be evaluated at runtime
constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    int x{5}; // not constexpr
    int y{6}; // not constexpr
    std::cout << greater(x, y) << " is greater!\n"; // will be evaluated at runtime
    return 0;
}