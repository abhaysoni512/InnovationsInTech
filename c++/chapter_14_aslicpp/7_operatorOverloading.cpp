#include <iostream>
#include <string_view>
using namespace std;
enum Color
{
    black,
    red,
    blue,
};
constexpr string_view getColor(Color c)
{
    switch (c)
    {
    case black:
        return "Black";
    case red:
        return "Red";
    case blue:
        return "Blue";
    default:
        return "Unknown";
    }
}
std::ostream &operator<<(std::ostream &os, Color c)
{
    return os << getColor(c);
}

int main()
{

    Color shirt{blue};
    std::cout << "Shirt Color is " << getColor(shirt) << std::endl;
    std::cout << "Shirt Color is " << shirt << std::endl;
}