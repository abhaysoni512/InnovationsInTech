#include <iostream>

int main()
{
    // Declare a 2D array of integers
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Accessing elements in the 2D array
    std::cout << "Element at (0,0): " << arr[0][0] << '\n'; // Output: 1
    std::cout << "Element at (1,2): " << arr[1][2] << '\n'; // Output: 7
    std::cout << "Element at (2,3): " << arr[2][3] << '\n'; // Output: 12
    // using for loop to iterate through the 2D array
    std::cout << "Elements in the 2D array:\n";
    for(size_t row{0}; row < std::size(arr) ; ++row){            // // std::size(arr) returns the number of rows
        for(size_t col{0}; col < std::size(arr[0]); ++col){         // std::size(arr[0]) returns the number of columns
            std::cout << arr[row][col] << ' '; // Output: 1 2 3 4 5 6 7 8 9 10 11 12
        }
        std::cout << '\n';
    }
    //using a range-based for loop to iterate through the 2D array
    std::cout << "Elements in the 2D array:\n";

    for(const auto& row : arr) {
        for(const auto& elem : row) {
            std::cout << elem << ' '; // Output: 1 2 3 4 5 6 7 8 9 10 11 12
        }
        std::cout << '\n';
    }

    return 0;
}