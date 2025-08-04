#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int N;
    cout<<"Enter Size : ";
    cin>>N;
    vector<vector<int>> v;
    for(int i{};i<N;i++){
        int n;
        cout<<"Enter ind vector size : ";
        cin>>n;
        vector<int> indV;
        for(int j{};j<n;j++){
            cout<<"Enter element : ";
            int x;
            cin>>x;
            indV.push_back(x);
        }
        v.push_back(indV);
    }

    for(const auto iv : v){
        for(const auto indele: iv){
            cout<<indele<<" ";
        }
    }
    return 0;
}