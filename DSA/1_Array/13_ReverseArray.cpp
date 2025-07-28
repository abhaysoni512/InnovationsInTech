#include <bits/stdc++.h>
using namespace std;
//m1: using auxillary array
template <typename T, auto S>
auto Reverse_Array(std::array<T,S> &arr){
    std::array<T,S> Aux_arr{};
    int i = 0;
    while(i<arr.size()){
        Aux_arr[i] = arr[arr.size()-1-i];
        i++;
    }
    return Aux_arr;

}

int main()
{
    std::array<int,10> arr{11,22,33,44,55,66,77,88,99,110};
    auto rev_arr = Reverse_Array(arr);
    cout<<"ele : ";
    for(int ele : rev_arr){
        cout<<ele<<" ";
    }
    cout<<"\n";
    return 0;
}