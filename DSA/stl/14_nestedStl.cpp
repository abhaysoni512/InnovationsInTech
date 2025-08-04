#include <bits/stdc++.h>
using namespace std;

int main(){
    map<pair<string,string>,vector<int>> mp;
    int n;
    cin>>n;
    for(int i{};i<n;i++){
        string fl,ll;
        int cnt;         // storing vector size
        cin>>fl>>ll>>cnt;
        for(int j{};j<cnt;j++){
            int x;
            cin>>x;
            mp[{fl,ll}].push_back(x);
        }
    }

    for(const auto &pr : mp){

        // pr is  element of map i.e. key
        const auto &full_name = pr.first;
        const auto &list = pr.second;
        cout<<full_name.first<<" "<<full_name.second<<endl;
        cout<<list.size()<<endl;
        for(const auto &eleinlist : list){
            cout<<eleinlist<<" ";
        }
        cout<<endl;

    }
    return 0;
}