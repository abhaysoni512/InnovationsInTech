#include <bits/stdc++.h>


using namespace std;
template<typename T, size_t Rows, size_t Cols>
using Array2D = std::array<std::array<T, Cols>, Rows>;

template<typename T, size_t Rows, size_t Cols>
void printArray(const Array2D<T, Rows, Cols>& arr) {
    for (const auto &row : arr) {
        for (const auto &elem : row) {
            cout << elem << ' ';
        }
        cout << '\n';
    }
}
template <typename T, size_t Rows, size_t Cols>
size_t getRowsCount(const Array2D<T, Rows, Cols>& arr) {
    return Rows;
}
template <typename T, size_t Rows, size_t Cols>
size_t getColsCount(const Array2D<T, Rows, Cols>& arr) {
    return Cols;
}
int main()
{
    Array2D<int, 3, 4> arr = {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}}; // note double braces
    printArray(arr);

    // Size of the array
    cout << "Number of rows: " << arr.size() << '\n'; // Output
    cout << "Number of columns: " << arr[0].size() << '\n'; // Output: 4

    // In order to get the length of the first dimension, we call size() on the array. To get the length of the second dimension, we first call arr[0] to get the first element,
    // and then call size() on that. To get the length of the third dimension of a 3-dimensional array, we would call arr[0][0].size().
    // However, the above code is flawed, as it will produce undefined behavior if any dimension other than the last has a length of 0 !return 0;

    // Best practice is to use std::size() and std::ssize() for getting the size of arrays in C++20 and later.
    cout << "Size of the array: " << std::size(arr) << '\n'; // Output: 3
    cout << "Size of the first row: " << std::size(arr[0]) << '\n'; // Output: 4

    // or write a function to get the size of the array
    cout << "Number of rows: " << getRowsCount(arr) << '\n'; // Output: 3
    cout << "Number of columns: " << getColsCount(arr) << '\n'; // Output: 4

    // Under c++23 , std::mdspan is a modifiable view that provides a multidimensional array interface for a contiguous sequence of elements. 
    // By modifiable view, we mean that a std::mdspan is not just a read-only view (like std::string_view) -- if the underlying sequence of elements is non-const, 
    // those elements can be modified.
    std::mdspan<int, std::extents<size_t, 3, 4>> mdspan(arr.data(), arr.size(), arr[0].size());
    cout << "Element at (0,0): " << mdspan(0, 0) << '\n'; // Output: 1
    cout << "Element at (1,2): " << mdspan(1, 2) << '\n'; // Output: 7
    cout << "Element at (2,3): " << mdspan(2, 3) << '\n'; // Output: 12

    
}