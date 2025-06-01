#include <iostream>

using namespace std;

int main(){
    int n =10;
    cout << "Address of n is " << &n << endl;
    int *p = &n;
    cout << "Address of p is " << p << endl;
    cout << "Value of p is " << *p << endl;
}