#include <bits/stdc++.h>
using namespace std;
template<typename T, size_t Rows, size_t Cols>
void printArray(const array<array<T, Cols>, Rows>& arr) {
    for (const auto& row : arr) {
        for (const auto& elem : row) {
            cout << elem << ' ';
        }
        cout << '\n';
    }
}
int main(){
    array<array<int, 3>, 2> arr = {{{1, 2, 3}, {4, 5, 6}}}; // note double braces

    cout << "Element at (0,0): " << arr[0][0] << '\n'; // Output: 1
    cout << "Element at (1,2): " << arr[1][2] << '\n'; // Output: 6
    // Array size
    cout << "Number of rows: " << arr.size() << '\n'; // Output: 2
    cout << "Number of columns: " << arr[0].size() << '\n'; // Output: 3

    for(auto& row : arr) {
        for(auto& elem : row) {
            cout << elem << ' '; // Output: 1 2 3 4 5 6
        }
        cout << '\n';
    }

    // passing a 2D array to a function
    printArray(arr);


    return 0;
}