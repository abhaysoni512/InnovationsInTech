#include <iostream>
#include "add.h" // Include the template definition

int main()
{
    std::cout << addOne(1) << '\n';   // Instantiates addOne<int>
    std::cout << addOne(2.3) << '\n'; // Instantiates addOne<double>

    return 0;
}