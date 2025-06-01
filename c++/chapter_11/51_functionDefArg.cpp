#include <iostream>

void print(int x, int y = 4) // 4 is the default argument
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

int main()
{
    print(1, 2); // x will use user-supplied argument 1
    print(3);    // x will use user-supplied argument 3, y will use default argument 4

    return 0;
}