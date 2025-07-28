#include <bits/stdc++.h>
using namespace std;

template <typename T, auto S>
bool IsSorted(std::array<T, S> &arr)
{
    int i{0};
    while(i!=arr.size()-1){
        if(arr[i]>arr[i+1]) return false;    
        i++;
    }
    return true;
}

int main()
{
    std::array<int, 10> arr{11, 22, 33, 44, 55, 66, 77, 88, 99,110};

    cout << "Original ele : ";
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << "\n";

    if(IsSorted(arr)) cout<<"Sorrted\n";
    else{
        cout<<"Not sorted\n";
    }

    return 0;
}