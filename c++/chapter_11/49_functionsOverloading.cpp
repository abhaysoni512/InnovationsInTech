
#include <iostream>
int add(int x, int y) // integer version
{
    return x + y;
}

double add(double x, double y) // floating point version
{
    return x + y;
}

int main()
{
    int a = 5, b = 6;
    double c = 5.5, d = 6.6;
    std::cout << add(a, b) << std::endl;
    std::cout << add(c, d) << std::endl;
    return 0;
}