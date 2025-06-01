#include <iostream>
using namespace std;

struct Something
{
    static inline int s_value{11}; // declare s_value as static (initializer moved below)
};


int main(){
    cout << Something::s_value << '\n'; // Accessing static member variable before any object is created
    return 0;
}