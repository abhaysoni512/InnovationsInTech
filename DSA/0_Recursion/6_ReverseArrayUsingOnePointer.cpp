#include <bits/stdc++.h>
using namespace std;
template<typename T, auto N>
void Swap(array<T, N>& arr, size_t index) {
    if (index >= N / 2) return; // Base case: when index reaches the middle
    swap(arr[index], arr[N - 1 - index]); // Swap elements
    Swap(arr, index + 1); // Recursive call with next index
}
int main(){
    array<int , 5> arr = {1, 2, 3, 4, 5};
    for(const auto& elem : arr) {
        cout << elem << " ";
    }
    cout << endl;

    Swap(arr,0);
    cout << "Reversed Array: ";
    for(const auto& elem : arr) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}