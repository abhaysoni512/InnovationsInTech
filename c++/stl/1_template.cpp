#include <iostream>

template <typename T>
T add(T a, T b)
{
    return a + b;
}
template <typename T>
T subtract(T a, T b)
{
    return a - b;
}
int main(){
    std::cout<<add(5,6)<<std::endl;
    std::cout<<add(5.5,6.6)<<std::endl;

    std::cout<<subtract(5,6)<<std::endl;
    std::cout<<subtract(5.5,6.6)<<std::endl;
    return 0;
}