#include <iostream>
#include <iterator> // for std::size and std::ssize

int main()
{
    const int prime[]{2, 3, 5, 7, 11}; // the compiler will deduce prime to have length 5

    /*
        In C++17, we can use std::size() (defined in the <iterator> header), which returns the array length as an unsigned integral value 
        (of type std::size_t).
        In C++20, we can also use std::ssize(), which returns the array length as a signed integral value (of a large signed integral type, 
        probably std::ptrdiff_t).
    */
    std::cout << std::size(prime) << '\n';  // C++17, returns unsigned integral value 5
    std::cout << std::ssize(prime) << '\n'; // C++20, returns signed integral value 5

    return 0;
}