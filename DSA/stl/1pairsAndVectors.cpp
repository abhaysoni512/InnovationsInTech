#include <bits/stdc++.h>
using namespace std;

int main(){
    pair<int,string> p;
   
    // value feeding
    p = make_pair(2,"abhay");

    cout<<p.first<<" "<<p.second<<endl;


    cout<<"--------------\n";
    // Usage:
    int a[] = {1,2,3};
    int b[] = {2,3,4};


    pair<int,int> p_arr[3];

    p_arr[0]={1,2};
    p_arr[1]={2,3};
    p_arr[2]={3,4};

    swap(p_arr[0],p_arr[2]);
    for(auto ele:p_arr){
        cout<<ele.first<<" "<<ele.second<<"\n";
    }
    return 0;
}