#include <iostream>

constexpr double calcCircumference(double radius)
{
    constexpr double pi{3.14159265359};
    return 2.0 * pi * radius;
}

int main()
{
    constexpr double circumference{calcCircumference(3.0)}; // compile error

    std::cout << "Our circle has circumference " << circumference << "\n";
}
 // Output:
/*
The code above will not compile because the  constexpr  variable  circumference  is initialized with a call to a function
that is not a  constexpr  function(means it's not a constant value it's value is decided at runtime).
To fix this, we can make the function  calcCircumference  a  constexpr  function.

double calcCircumference(double radius)
{
    constexpr double pi{3.14159265359};
    return 2.0 * pi * radius;
}
💡 Why does this cause a compile-time error?

The function calcCircumference is not marked as constexpr.
This means the compiler cannot evaluate its result at compile-time.
But constexpr double circumference requires a compile-time constant value.
*/