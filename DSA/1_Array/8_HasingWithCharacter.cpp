#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int Hashh[256]={};
    for(int i{0};i<s.size();i++){
        Hashh[s[i]]++;
    }
    int q;
    cin>>q;
    cin.ignore();
    while(q--){
        char c;
        cin>>c;
        cout<<"Your query "<<c<<" appeared "<<Hashh[c-'a']<<" times\n";
    }
    return 0;
} 