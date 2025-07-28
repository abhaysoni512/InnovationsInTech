#include <bits/stdc++.h>
using namespace std;
template <typename T, auto S1, auto S2>
auto mergeArray(std::array<T,S1> &arr1 ,std::array<T,S2> &arr2){
    std::array<T,S1+S2>arr{};
    int i ,j,k;
    i=j=k=0;
    while(i< S1 && j< S2){
        if(arr[i]<arr[j]){ 
            arr[k++] = arr1[i++];
        }
        else {
            arr[k++] = arr2[j++];
        }   
    }
    while(i<S1){
        arr[k++] = arr1[i++];
    }
    while(j<S2){
        arr[k++] = arr2[j++];
    }
    return arr;

} 


int main()
{
    std::array<int,5> arr1{1,3,5,7,9};
    std::array<int,6> arr2{2,4,6,8,10,11};
    auto mergedArr = mergeArray(arr1,arr2);
    cout<<"Element : ";
    for(const int &ele : mergedArr){
        cout<< ele <<" ";
    }
    return 0;
}