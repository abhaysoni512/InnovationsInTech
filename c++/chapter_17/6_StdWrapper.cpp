/*
    we mentioned that arrays can have elements of any object type.
    This includes objects with fundamental types (e.g. int) and objects with compound types
    (e.g. pointer to int).

    However, because references are not objects, you cannot make an array of references.
     The elements of an array must also be assignable, and references can’t be reseated.

*/

#include <iostream>
#include <array>
#include <functional>
using namespace std;

int main(){
    int x{1};
    int y{2};

   // [[maybe_unused]] std::array<int &, 2> refarr{x, y}; // compile error: cannot define array of references
    int &ref1{x};
    int &ref2{y};
    [[maybe_unused]] std::array valarr{ref1, ref2}; // ok: this is actually a std::array<int, 2>, not an array of references

    cout << "valarr[0]: " << valarr[0] << endl; // prints 1
    cout << "valarr[1]: " << valarr[1] << endl; // prints 2

    // You can use std::ref to create a reference wrapper
    std::array<std::reference_wrapper<int>, 2> refarr{x, y}; // ok: this is an array of reference wrappers
    cout << "refarr[0]: " << refarr[0] << endl; // prints 1
    cout << "refarr[1]: " << refarr[1] << endl; // prints 2

    // to modify the values through the reference wrappers
    refarr[0].get() = 10; // modifies x
    refarr[1].get() = 20; // modifies y

    // Note that we must use arr[1].get() = 5 and not arr[1] = 5. 
    //The latter is ambiguous, as the compiler can’t tell if we intend to reseat the std::reference_wrapper<int> to value 5 
    //(something that is illegal anyway) or change the value being referenced. Using get() disambiguates this.

    
}