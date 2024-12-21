#include <iostream>
using namespace std;
int main()
{
    int y;
    int x=(y=5);
    std::cout << x <<","<< y <<endl; // print how many bytes of memory an int value takes

    return 0;
}