// Const objects may not call non - const member functions

#include <iostream>

struct Date
{
    int year{};
    int month{};
    int day{};
    #if 0
    void print()     // non-const member function
    {
        std::cout << year << '/' << month << '/' << day;
    }
    #endif
    void print() const  // const member function
    {
        std::cout << year << '/' << month << '/' << day;
    }
};

int main()
{
    const Date today{2020, 10, 14}; // const

    today.print(); // compile error: can't call non-const member function

    return 0;
}