#include <iostream>

namespace Foo::Goo
{
    int add(int x, int y)
    {
        return x + y;
    }
}

int main()
{
    namespace Active = Foo::Goo; // active now refers to Foo::Goo

    std::cout << Active::add(1, 2) << '\n'; // This is really Foo::Goo::add()

    return 0;
} // The Active alias ends here