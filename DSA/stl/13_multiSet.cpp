#include <bits/stdc++.h>
using namespace std;

int main(){
    multiset<string> s;
    s.insert("abc");
    s.insert("pqr");
    s.insert("abc");
    s.insert("xyx");

    for(const auto &str: s){
        cout<<str<<endl;
    }
    return 0;
}