#include <iostream>
#include <algorithm>
#include <iterator> // for std::size and std::ssize
int main(){
    int arr1[]{1,2,3,4,5}; // C-style array with 5 elements
    int arr2[5]; // C-style array with 5 elements

    static_assert(std::ssize(arr1) == std::ssize(arr2), "arr1 should have 5 elements");

    // Copying elements from arr1 to arr2 using std::copy
    std::copy(std::begin(arr1), std::end(arr1), std::begin(arr2));
    // Displaying the elements of arr2
    std::cout << "Elements of arr2 after copy: ";
    for (const auto& elem : arr2) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
 
}