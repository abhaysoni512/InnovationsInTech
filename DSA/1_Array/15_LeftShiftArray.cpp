#include <bits/stdc++.h>
using namespace std;

template <typename T, auto S>
void Left_shift(std::array<T, S> &arr)
{
    int i = 0;
    while(i<arr.size()-1){
        arr[i] = arr[i+1];
        i++;
    }
    arr[i] = 0;
}

int main()
{
    std::array<int, 10> arr{11, 22, 33, 44, 55, 66, 77, 88, 99, 110};
    cout << "Original ele : ";
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << "\n";
    Left_shift(arr);
    cout<< "left shift array : ";
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << "\n";

    return 0;
}