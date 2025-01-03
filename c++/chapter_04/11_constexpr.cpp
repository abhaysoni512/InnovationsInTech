#include <iostream>

int main()
{

    constexpr int a{11};
    constexpr int b{a}; // no error as a is constant value

    const int c{a};     // no error as a is constant value
    constexpr int d{c}; // no error as a is constant value

    int sum;
    // constexpr int e{sum}; // error sum is not a constant value
}