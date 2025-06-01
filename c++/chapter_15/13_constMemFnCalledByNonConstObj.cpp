//  Const member functions may also be called on non - const objects:

// A member function that does not (and will not ever) modify the state of the object should be made const,
// so that it can be called on both const and non-const objects.

#include <iostream>

struct Date
{
    int year{};
    int month{};
    int day{};

    void print() const // const
    {
        std::cout << year << '/' << month << '/' << day;
    }
};

int main()
{
    Date today{2020, 10, 14}; // non-const

    today.print(); // ok: can call const member function on non-const object

    return 0;
}