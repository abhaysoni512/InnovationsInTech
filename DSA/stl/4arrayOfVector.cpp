#include <bits/stdc++.h>
using namespace std;
void printVectors(const vector<int> &v){
    for(int i =0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int N;
    cin>>N;
    vector<int> v[N];
    for(int i=0;i<N;i++){
        // Individual vector m kitna size rhkna h
        cout<<" Enter individual vector size : ";
        int size;
        cin>>size;
        cout<<"Now Enter element to feed"<<endl;
        int val;
        for(int j=0;j<size;j++){
            cin>>val;
            v[i].push_back(val);
        }
    }
    for(int j = 0;j<N;j++){
        cout<<"v["<<j<<"]";
        printVectors(v[j]);
    }
    
    return 0;
}