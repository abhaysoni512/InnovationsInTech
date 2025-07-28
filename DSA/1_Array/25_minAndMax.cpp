#include <bits/stdc++.h>
using namespace std;

int main(){
    std::array arr{6,3,8,10,16,7,5,2,9,14};
    int min =arr[0], max = arr[0];

    for(int i{1};i<arr.size();i++){
        if(arr[i]<min) min = arr[i];
        if(arr[i]>max) max = arr[i];
    }
    cout<<"Min and Max : "<<min<<" "<<max<<endl;
    return 0;
}