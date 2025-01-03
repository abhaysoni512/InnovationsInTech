#include <iostream>
using namespace std;

int add(int x, int y)
{
    return x + y;
}

int main()
{
    std::cout << "2+4= " << add(2, 4) << endl;
    return 0;
}
