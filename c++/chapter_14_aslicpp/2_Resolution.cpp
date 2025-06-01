// classic example of unscoped enum with name collioson
// Sol: using namespace


#include <iostream>
namespace Color{
    enum Color
    {
        red,
        green,
        blue, // blue is put into the global namespace
    };
}
namespace Feeling{
    enum Feeling
    {
        happy,
        tired,
        blue, // error: naming collision with the above blue
    };
}
int main()
{
    Color::Color apple{Color::red};  // my apple is red
    Feeling::Feeling me{Feeling::happy}; // I'm happy right now (even though my program doesn't compile)

    return 0;
}