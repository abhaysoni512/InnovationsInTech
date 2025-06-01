#include <iostream>
#include <string>
#include <string_view>

int main()
{
    std::string s = "Hello";
    std::string_view sv = s; // sv points to s's internal buffer

    s += ", World!"; // May reallocate s's memory

    std::cout << sv << '\n'; // Undefined behavior: sv points to invalid memory 
    return 0;
}
