#include <iostream>

enum Color
{
    black,   // 0
    red,     // 1
    blue,    // 2
    green,   // 3
    white,   // 4
    cyan,    // 5
    yellow,  // 6
    magenta, // 7
};

int main()
{
    Color shirt{blue}; // shirt actually stores integral value 2
    std::cout << "Size of Color enum: " << sizeof(shirt) << '\n'; // prints 4
    return 0;
}
