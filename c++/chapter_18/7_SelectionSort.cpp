#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    constexpr int size = static_cast<int>(sizeof(arr) / sizeof(arr[0]));

    for(int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
    cout << "Sorted array: ";
    for(const auto& elem : arr) {
        cout << elem << " ";
    }
    cout << endl;

    int array[]{30, 50, 20, 10, 40};
    sort(begin(array), end(array));
    cout << "Sorted array using std::sort: ";
    for(const auto& elem : array) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}