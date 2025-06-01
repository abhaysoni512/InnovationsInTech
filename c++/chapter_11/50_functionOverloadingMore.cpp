#include <iostream>

void print(int x)
{
    std::cout << x << "\n";
}

void print(double d)
{
    std::cout << d << '\n';
}

int main()
{
    print('a'); // char does not match int or double, so what happens?
    //print(5L);  // long does not match int or double, so what happens?

    return 0;
}