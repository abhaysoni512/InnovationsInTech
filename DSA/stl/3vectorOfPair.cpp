#include <bits/stdc++.h>
using namespace std;
void printVector(const vector<pair<int, int>>  &v)
{
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}
int main(){
    //vector<pair<int,int>> v{{1,2},{2,3},{3,4},{4,5}};
    vector<pair<int, int>> v;

    printVector(v);
    cout<<"Vector size: ";
    int no;
    cin>>no;
    int x,y;
    for(int i{0};i<no;i++){
        cout << "Enter x and y : ";
        cin>>x>>y;
        v.push_back({x,y});
    }
    printVector(v);

    // array of vector

    vector<int> v[10];
    
    return 0;
}