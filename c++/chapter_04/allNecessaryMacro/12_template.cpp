#include <iostream>

// Abbreviated function template (C++20 feature)
auto max(auto x, auto y)
{
    return (x < y) ? y : x;
}

// The above function expands to the following template:
//
// template <typename T, typename U>
// auto max(T x, U y) {
//     return (x < y) ? y : x;
// }

int main()
{
    std::cout << "Max of 10 and 20: " << max(10, 20) << "\n";
    std::cout << "Max of 3.14 and 2.71: " << max(3.14, 2.71) << "\n";
    std::cout << "Max of 'A' and 'Z': " << max('A', 'Z') << "\n";
    return 0;
}
