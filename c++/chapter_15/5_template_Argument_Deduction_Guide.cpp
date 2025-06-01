// Template Argument Deduction Guide
// C++17 introduced Template Argument Deduction Guide (TADG) which allows the deduction of template arguments
// from the initializer list.

#include <iostream>
#include <utility> // for std::pair

// define our own Pair type
template <typename T, typename U>
struct Pair
{
    T first{};
    U second{};
};

int main()
{
    Pair<int, int> p1{1, 2}; // ok: we're explicitly specifying the template arguments
    Pair p2{1, 2};           // compile error in C++17 (okay in C++20)

    return 0;
}