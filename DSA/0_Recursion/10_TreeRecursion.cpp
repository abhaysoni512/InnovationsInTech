#include <bits/stdc++.h>
using namespace std;
void fun(int n){
    if(n){
        cout<<n<<" ";
        fun(n-1);
        fun(n-1);
    }
}
int main(){
    int a =3;
    fun(a);
    return 0;
}