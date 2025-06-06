#include <iostream>
int value{5}; // global variable

int main()
{
    int value{7}; // hides the global variable value
    ++value;      // increments local value, not global value

    --(::value); // watch out: decrements global value, not local value (parenthesis added for readability)

    std::cout << "local variable value: " << value << '\n';
    std::cout << "global variable value: " << ::value << '\n';

    return 0;
} // local value is destroyed
