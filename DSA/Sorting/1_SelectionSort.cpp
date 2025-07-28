#include <bits/stdc++.h>
using namespace std;
template <typename T, auto N>
void selection_sort(array<T,N>&arr){
    for(int i{0};i<N-1;i++){
        int mini = i;
        for(int j{i};j<N;j++){
            if(arr[j]<arr[mini]) mini = j;
        }
        swap(arr[i],arr[mini]);
    }
}
int main(){
    array arr{13,46,24,52,20,9};
    for(const auto &ele:arr){
        cout<<"Element in array: "<<ele<<" \n";
    }
    cout<<"\n";
    selection_sort(arr);
    for (const auto &ele : arr)
    {
        cout << "Element in array after selection sort: " << ele << " \n";
    }
    cout << "\n";
    return 0;
}