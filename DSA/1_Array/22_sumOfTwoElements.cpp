#include <bits/stdc++.h>
using namespace std;

int main(){
    std::array arr{6,3,8,10,16,7,5,2,9,14};
    cout<<"Enter sum value = ";
    int k;
    cin>>k;
    cout<<"\n";
    for(int i{0};i<arr.size()-1;i++){
        for (int j{i + 1}; j < arr.size() - 1 ;j++){
            if(arr[i] + arr[j]==k)
                cout<<"arr["<<i<<"] : "<<arr[i] <<" + arr["<<j<<"] : "<<arr[j]<<" = "<<k<<endl;
        }
    }
    return 0;
}