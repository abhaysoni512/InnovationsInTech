#include <iostream>

using namespace std;

int foo() {
    return 42;
}

int goo() {
    return 84;
}

int roo(int x) {
    return x * 2;
}

int main(){
    auto(*fcnPtr)() = foo; // Pointer to a function that takes no arguments and returns an int
    cout << "Calling foo through fcnPtr: " << fcnPtr() << endl; // prints 42

    fcnPtr = goo; // Reassign the function pointer to point to goo
    cout << "Calling goo through fcnPtr: " << fcnPtr() << endl; // prints 84

    auto (*fcnPtrWithArg)(int) = roo; // Pointer to a function that takes an int argument and returns an int
    cout << "Calling roo through fcnPtrWithArg with argument 5: " << fcnPtrWithArg(5) << endl; // prints 10

    return 0;
}