#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string,int> mp;
    int n;
    
    cout<<"Enter no of string to check: ";
    cin >> n;
    string s{};
    
    for (int i{}; i < n; i++)
    {
        cout<<"Enter String : ";
        cin>>s;
        mp[s]++;    
    }
    cout<<"\n";
    for(const auto &it:mp){
        cout<<it.first<<" <-> "<<it.second<<endl;
    }
    cout << "\n";
    return 0;
}