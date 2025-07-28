#include <bits/stdc++.h>
using namespace std;

template <typename T, auto S>
void positiveNegativeArray(std::array<T,S> &arr){
    int i{0};
    int j{S-1};
    while(i<j){
        while(arr[i]<0) i++;
        while(arr[j]>=0) j--;
        if(i<j) swap(arr[i],arr[j]);
    }
}

int main()
{
    std::array<int,10> arr{-1,33,0,-3,11,33,44,-4,19,-3};

    cout << "Original ele : ";
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << "\n";
    positiveNegativeArray(arr);
    cout << "separated ele : ";
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << "\n";

    return 0;
}