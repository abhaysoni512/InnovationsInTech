#include <iostream>

struct Something
{
    static int s_value; // declare s_value as static (initializer moved below)
};

int Something::s_value{1}; // define and initialize s_value to 1 (we'll discuss this section below)

int main()
{
    Something first{};
    Something second{};

    first.s_value = 2;

    std::cout << first.s_value << '\n';
    std::cout << second.s_value << '\n';
    return 0;
}