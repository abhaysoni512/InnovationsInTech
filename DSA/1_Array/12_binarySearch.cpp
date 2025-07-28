#include <bits/stdc++.h>
using namespace std;

template <typename T, auto S> 
int AlgorithmBinarySearch(std::array <T,S> &Arr, int l = 0,int h = S-1,int key = 0){
    while(l<=h){
        int mid = (l + h)/2;
        if(key==Arr[mid]) return mid;
        else if(key < Arr[mid]) h = mid-1;
        else l = mid +1;
    }
    return INT32_MIN;
}
int main(){
    std::array<int, 10> arr{11, 22, 33, 44, 55, 66, 77, 88, 99, 100};
    std::sort(arr.begin(),arr.end());
    int key;
    cin>>key; 
    int res= AlgorithmBinarySearch(arr,0,10,key);

    if (res == INT32_MIN)
        cout << key << " not found\n";
    else {
        cout << key << "  found at "<< res <<"\n";
    }
    return 0;
}