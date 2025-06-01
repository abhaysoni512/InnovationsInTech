// Const objects may not call non - const member functions

#include <iostream>

struct Date
{
    int year{};
    int month{};
    int day{};
    void print() const  // const member function
    {
        std::cout << ++year << '/' << month << '/' << day; // compile error: can't modify member variables
    }
    // error: cannot assign to non-static data member within const member function 'print'
};

int main()
{
    const Date today{2020, 10, 14}; // const

    today.print(); // compile error: can't call non-const member function

    return 0;
}