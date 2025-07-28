// using two pointers to swap elements of an array using recursion

#include <bits/stdc++.h>
using namespace std;
template <typename T, size_t N>
void RevArr(array<T, N>& arr, size_t start = 0, size_t end = N - 1) {
   if(start>=end) return;
    swap(arr[start],arr[end]);
    RevArr(arr,start+1,end-1);
}

int main(){
    std::array<int , 5> arr = {1, 2, 3, 4, 5};
    std::cout << "Array length: " << arr.size() << std::endl;
    std::cout << "Array elements: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    RevArr(arr, 0 , arr.size() - 1);
    std::cout << "Rev Array elements: ";
    for (const auto &elem : arr)
    {
        std::cout << elem << " ";
    }
    return 0;
}