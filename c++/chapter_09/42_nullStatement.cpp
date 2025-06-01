//program to show null statement
#include <iostream>
using namespace std;

int main()
{
    int x = 5;
    // if (x == 5); // null statement
    if (x == 5)
        ; // null statement
    cout << "This statement will always execute\n";
    return 0;
}