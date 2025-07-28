#include <bits/stdc++.h>
using namespace std;
//m2 :
template <typename T, auto S>
void Reverse_Array(std::array<T,S> &arr){
    int i = 0;
    while(i != (int)S/2){
        swap(arr[i],arr[S-1-i]);
        i++;
    }
}

int main()
{
    std::array<int,10> arr{11,22,33,44,55,66,77,88,99,110};
    cout<<"Original ele : ";
    for(int ele : arr){
        cout<<ele<<" ";
    }
    cout<<"\n";
    Reverse_Array(arr);
    cout << "Reverse ele : ";
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << "\n";
    return 0;
}