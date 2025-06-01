#include <iostream>
//usage to allow redefinition if we remove inline it will throw error
inline double pi()
{
    std::cout << "pi() main is called\n";
    return 3.14;
}
int main()
{
    std::cout << pi() << '\n';
    
    return 0;
}