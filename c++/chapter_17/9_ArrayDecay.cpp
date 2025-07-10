/*
    Array to pointer conversions (array decay)
    In most cases, when a C-style array is used in an expression, the array will be implicitly converted into a pointer to the element type,
    initialized with the address of the first element (with index 0).
    Colloquially, this is called array decay (or just decay for short).

    In C++, there are a few common cases where an C-style array doesn’t decay:
        ->   When used as an argument to sizeof() or typeid().
        ->   When taking the address of the array using operator&.
        ->   When passed as a member of a class type.
        ->   When passed by reference.
*/

#include <iostream>
#include <iomanip> // for std::boolalpha

int main(){
    int arr[5]{1, 2, 3, 4, 5}; // C-style array with 5 elements

    // Displaying the address of the array
    std::cout << "Address of arr: " << &arr << '\n';

    // Displaying the address of the first element
    std::cout << "Address of arr[0]: " << &arr[0] << '\n';

    auto *ptr1{&arr[0]}; // Pointer to the first element of the array
    std::cout << std::boolalpha << (ptr1 == arr) << '\n'; // true, because arr decays to a pointer to its first element

    auto *ptr2{arr}; // Pointer to the first element of the array
    std::cout << std::boolalpha << (ptr2 == arr) << '\n'; // true, because arr decays to a pointer to its first element

    return 0;
}