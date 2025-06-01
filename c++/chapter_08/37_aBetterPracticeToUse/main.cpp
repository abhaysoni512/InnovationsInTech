#include <iostream>

#if 0
namespace constants
{
    extern const double gravity; // forward declaration
}
#endif

double getGravity(); // forward declaration

int main()
{
    std::cout << getGravity() << '\n'; //No direct access to global variable

    return 0;
}