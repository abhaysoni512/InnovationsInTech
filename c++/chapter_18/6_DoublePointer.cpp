#include <iostream>

int main(){
    int a{10};
    int *p1{&a}; // Pointer to a
    int **p2{&p1}; // Pointer to pointer to a


    std::cout << "Value of a: " << a << std::endl; // Output: 10
    std::cout << "Value of p1: " << *p1 << std::endl; // Output: 10
    std::cout << "Value of p2: " << **p2 << std::endl; // Output: 10

    std::cout <<"-------------------------" << std::endl;

    std::cout << "Address of p1: " << p1 << std::endl; // Output: Address of p1
    std::cout << "Address of p1: " << *p2 << std::endl; // Output: Address of p1

    /* 
        int a{10}; // Declare an integer variable a and initialize it to 10
        int **p2(&&a); // Not a valid syntax, as && is used for rvalue references, not for pointers.

    */

    // use case of double pointer
    // Arrays of pointers
    int **ptr{new int*[3]}; // Dynamically allocate an array of 3 integer pointers
    
    // Assign values to the pointers 
    ptr[0] = new int(1);
    ptr[1] = new int(2);
    ptr[2] = new int(3);

    // Print the values pointed to by the pointers
    for(int i = 0; i < 3; ++i) {
        std::cout << "Value at ptr[" << i << "]: " << *ptr[i] << std::endl; // Output: 1, 2, 3
    }

    // Clean up dynamically allocated memory
    for(int i = 0; i < 3; ++i) {
        delete ptr[i]; // Delete each integer
    }
    delete[] ptr; // Delete the array of pointers
    std::cout << "Memory cleaned up." << std::endl;

    std::cout << "-------------------------" << std::endl;

    // Usage of double pointer in 2D arrays
    // int **array{new int[10][5]}; // won’t work!

    int row{3};
    int (*array)[5]{new int[row][5]}; // Correct way to allocate a 2D array dynamically

    // Assign values to the 2D array
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < 5; ++j) {
            array[i][j] = i * 5 + j; // Fill with some values
        }
    }
    // Print the 2D array
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < 5; ++j) {
            std::cout << "array[" << i << "][" << j << "] = " << array[i][j] << std::endl;
        }
    }
    // Clean up dynamically allocated memory
    delete[] array; // Delete the 2D array
    std::cout << "2D array memory cleaned up." << std::endl;

    return 0;
}