#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v{11,22,33,44};
    vector <int> ::iterator it = v.begin();
    cout<< *it<<endl;


    while(it!=v.end()){
        cout << *it << " ";
        it++;
    }
    cout<<endl;
    vector<pair<int,int>> v_p {{11,22},{22,33},{33,44}};

    vector<pair<int,int>> ::iterator it1 = v_p.begin(); 
    
    for(;it1!=v_p.end();it1++){
        //cout<< (*it1).first<<" "<<" <-> "<<(*it1).second<<endl;
        cout<<it1->first<<" "<<" <-> "<<it1->second<<endl;
    }
    
    cout<<endl;
    cout<<endl;
    for(const auto &value : v_p){
        cout<<value.first<<" <-> "<<value.second<<endl;
    }
    cout<<endl; 
    return 0;

}