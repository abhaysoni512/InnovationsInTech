

#include <bits/stdc++.h>
using namespace std;
template <typename T>
void mySwap(T &a,T &b){
    T temp = std::move(a);  // to use move assignement operator
    a = std::move(b);
    b = std::move(temp);
}
int main(){
    string x{"abc"};
    string y{"de"};
    cout<<"x : "<<x<<" ,y :"<<y<<endl;

    mySwap(x,y);

    cout << "x : " << x << " ,y :" << y << endl;

    return 0;
}