#include <bits/stdc++.h>
using namespace std;
int foo(){
    return 42;
}
int main(){
    // how to print the address of a function
    cout << "Address of foo: " << reinterpret_cast<void*>(foo) << endl;

    /*
        Just like it is possible to declare a non-constant pointer to a normal variable,
         it’s also possible to declare a non-constant pointer to a function. 
        In the rest of this lesson, we’ll examine these function pointers and their uses
    */
    // Declare a function pointer
    int (*fcnPtr)() = foo; // Pointer to a function that takes no arguments and returns an int

    // Call the function using the pointer
    cout << "Calling foo through fcnPtr: " << fcnPtr() << endl; // prints 42

    // To make a const function pointer, the const goes after the asterisk:
    int (*const constFcnPtr)() = foo; // Pointer to a function that takes no arguments and returns an int, and is constant
    // Call the function using the const pointer
    cout << "Calling foo through constFcnPtr: " << constFcnPtr() << endl; // prints 42

        return 0;
}