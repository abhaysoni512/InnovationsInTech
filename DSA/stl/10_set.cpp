#include <bits/stdc++.h>
using namespace std;
void printSet(const set<string> &s){
    for(const auto &string_s : s){
        cout<<string_s<<endl;
    }
}
int main(){
    //sets, unordered sets, multisets
    // sets are collections of similar elements

    set<string> s;
    s.insert("abc"); //logn
    s.insert("pqr");
    s.insert("ddd");
    //printing set
    printSet(s);

    auto it = s.find("abc");
    if(it!=s.end()){
        cout<<*it<<endl;
    }
    return 0;
}