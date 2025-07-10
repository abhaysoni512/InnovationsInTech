#include <iostream>
#include <array>
using namespace std;
int main(){
    array <int, 5> arr{1, 2, 3, 4, 5};
    auto begin{ &arr[0] }; // Pointer to the first element

    auto end{ &arr[0] + arr.size() }; // Pointer to one past the last element
    for(auto it{begin}; it != end; ++it) {
        cout << *it << " "; // Dereference the pointer to get the value
    }
    cout << endl;
}