//program for unamed namespace
//usage to limit scope of variables to a current file w/o using static keyword
#include <iostream>
using namespace std;

namespace
{
    int x = 10;
    int y = 20;
}

int main()
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    return 0;
}
