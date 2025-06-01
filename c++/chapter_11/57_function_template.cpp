#include <iostream>

// a declaration for our function template (we don't need the definition any more)
template <typename T>
T max(T x, T y);

template <>
int max<int>(int x, int y) // the generated function max<int>(int, int)
{
    return (x < y) ? y : x;
}

template <>
double max<double>(double x, double y) // the generated function max<double>(double, double)
{
    return (x < y) ? y : x;
}
double max(double x, double y) // the generated function max<double>(double, double)
{
    std::cout << "Non template function\n"; // (with no angled brackets), the compiler will consider both max<int> template function overloads 
                                            // and max non-template function overloads. When the bottom case results in both a template function 
                                            // and a non-template function that are equally viable, the non-template function will be preferred.
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max<int>(1, 2) << '\n';    // instantiates and calls function max<int>(int, int)
    std::cout << max<int>(4, 3) << '\n';    // calls already instantiated function max<int>(int, int)
    std::cout << max<double>(1, 2) << '\n'; // instantiates and calls function max<double>(double, double)
    std::cout << max(1.1, 2.2) << '\n';     // instantiates and calls function max<double>(double, double) 
                                            // (the compiler will consider both max<int> template function overloads 
                                            //and max non-template function overloads)
    std::cout << max<>(1.1, 2.2) << '\n';   // instantiates and calls function max<double>(double, double)
                                            //non template function will not be considered.

    return 0;
}