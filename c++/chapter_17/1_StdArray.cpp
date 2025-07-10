/*
    Std:: Array :
        std::array is a fixed-size array that is part of the C++ Standard Library, introduced in C++11.
        It is a wrapper around a C-style array and provides a safer and more convenient interface for working with arrays.

    When to use std::array?
        Use std::array for constexpr arrays

    When to use std::vector?
        std::vector for non-constexpr arrays.

*/

#include <iostream>
#include <array>
#include <vector>

int main(){
    // Definition
    std::array<int, 5> arr {}; // Fixed size array of integers of size 5, initialized to zero
    std::vector<int> vec(5); //  Dynamic size array of integers, initialized with 5 elements (default value is 0)

    // Note : The length of a std::array must be a constant expression

    // Aggregate initialization of a std::array
    std::array<int, 5> arr2 {1, 2, 3, 4, 5}; // Aggregate initialization with values
    std::vector<int> vec2 {1, 2, 3, 4, 5}; // Aggregate initialization with values

    // Class template argument deduction (CTAD) for std::array C++17
    std::array arr3 {1, 2, 3, 4, 5}; // C++17 CTAD, deduces type as std::array<int, 5>
    std::vector vec3 {1, 2, 3, 4, 5}; // C++17 CTAD, deduces type as std::vector<int>

    // Omitting just the array length using std::to_array C++20
    auto arr4 = std::to_array({1, 2, 3, 4, 5}); // C++20, deduces type as std::array<int, 5>

    // std::get() does compile-time bounds checking for constexpr indices
    std::cout << "Element at index 2 in arr2: " << std::get<2>(arr2) << std::endl; // Accessing element at index 2
    std::cout << "Element at index 2 in vec2: " << vec2.at(2) << std::endl; // Accessing element at index 2 with bounds checking

}