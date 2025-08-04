#include <bits/stdc++.h>
using namespace std;

int main(){
    // will be stored order by key 1 2 3 4
    map<int,string> m;
    m[1] = "abc";       // Insertion takes o(logn)
    m[3] = "xyz";
    m[2] = "pqr";
    m.insert({4,"sdf"});
    m.insert({4,"xxx"});   // still showing sdf
    m[4]= "xxx";            // here it will change
    map<int, string> ::iterator it1 = m.begin();
    for(;it1!=m.end();it1++){
        cout<<it1->first<<" <-> "<<it1->second<<"\n";
    }
    cout<<endl;
    
    // it will store value of m 
    for (const auto &it : m)
    {
        cout<<it.first<<" <-> "<<it.second<<" \n";
    }
    cout<<endl;

    // how to find key occurs or not
    auto it = m.find(3);    // log(n) : self balancing tree
    if(it!=m.end()){
        cout<<"Key three found : "<<it->first<<" <-> "<<it->second<<endl;
    }

    //erasing 
    m.erase(3);     //log(n)
    //or we can erase like
    auto it3 = m.find(4);
    if(it3!=m.end())
        m.erase(it3);
    // it will store value of m
    for (const auto &it : m)
    {
        cout << it.first << " <-> " << it.second << " \n";
    }
    cout << endl;

    return 0;
}