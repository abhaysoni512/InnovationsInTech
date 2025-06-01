#include <iostream>

namespace Foo
{
    namespace Goo // Goo is a namespace inside the Foo namespace
    {
        int add(int x, int y)
        {
            return x + y;
        }
    }
}
// C++17, nested namespaces can also be declared this way:

namespace Roo::Goo 
{
    int sub(int x, int y)
    {
        return x - y;
    }
}

namespace Roo
{
    void print(){
        std::cout<<"Roo : print()"<<std::endl;
    }
}

int main()
{
    std::cout << Foo::Goo::add(1, 2) << '\n';
    std::cout << Roo::Goo::sub(1, 2) << '\n';
    Roo::print();
    return 0;
}