#include <iostream>
using namespace std;

int main(){
    std::cout << "Enter the size of the array: ";
    int size;
    cin >> size;

    int *arr{new (std::nothrow) int[size]{}};
    if(arr) {
        for (int i = 0; i < size; ++i) {
            arr[i] = i * 10; // Initialize the array with some values
        }

        std::cout << "Array elements: ";
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        delete[] arr; // Free the allocated memory
    } else {
        std::cout << "Memory allocation failed." << std::endl;
    }
    return 0;
}