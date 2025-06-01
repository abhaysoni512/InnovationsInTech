#include <iostream>

template <typename T>
void print(T val, int times = 1)
{
    while (times--)
    {
        std::cout << val;
    }
}
int main()
{
    print(5);      // print 5 1 time
    print('a', 3); // print 'a' 3 times

    return 0;
}