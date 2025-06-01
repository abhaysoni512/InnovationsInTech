#include <iostream>
struct Something
{
    static int s_value; // declare s_value as static (initializer moved below)
};

int Something::s_value{1}; // define and initialize s_value to 1 (we'll discuss this section below)
// Note: The static member variable is defined outside the class, which is necessary for it to have a single instance shared by all objects of the class.

int main()
{ std::cout << Something::s_value << '\n'; // Accessing static member variable before any object is created
    return 0;
}