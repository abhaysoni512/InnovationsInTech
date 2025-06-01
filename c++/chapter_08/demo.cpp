// This program calculates the sum of two numbers using a function
#include <iostream>

int sum (int a, int b)
{
    return a + b;
}

int main()
{
    int a {5};
    int b {7};

    std::cout << "Sum of " << a << " and " << b << " is " << sum(a, b) << '\n';

    return 0;
}
