#include <bits/stdc++.h>
using namespace std;

int main(){
    // size of array
    int n;
    cin>>n;
    int arr[n];
    for(int i{0};i<n;i++){
        cin>>arr[i];
    }
    //pre compution using optimize memory use
    map<int,int> mpp;
    for(int i{0};i<n;i++){
        mpp[arr[i]]++;
    }
    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        cout<<number<<" appears "<< mpp[number]<< " times\n";
    }

    return 0;
}