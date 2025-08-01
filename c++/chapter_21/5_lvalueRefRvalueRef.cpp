#include <iostream>

void fun(const int &lref) // l-value arguments will select this function
{
    std::cout << "l-value reference to const: " << lref << '\n';
}

void fun(int &&rref) // r-value arguments will select this function
{
    std::cout << "r-value reference: " << rref << '\n';
}

int main()
{
    int x{5};
    fun(x); // l-value argument calls l-value version of function
    fun(5); // r-value argument calls r-value version of function

    int &&ref{5}; // Note: You already know that literal 5 is an rvalue of type int, and int x is an lvalue of type int. Similarly, int&& ref is an lvalue of type int&&.
    fun(ref);
    return 0;
}