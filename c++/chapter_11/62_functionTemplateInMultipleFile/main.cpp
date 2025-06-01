#include <iostream>

template <typename T>
T addOne(T x); // Function template forward declaration

int main()
{
    std::cout << addOne(1) << '\n';   // Calls addOne<int>(1)
    std::cout << addOne(2.3) << '\n'; // Calls addOne<double>(2.3)

    return 0;
}