#include <bits/stdc++.h>
using namespace std;
void f(int i, int N){
    if(i> N) return ;
    cout<<i << endl;
    f(++i,N);
}
int main(){
    int n;
    cin >> n;
    f(1,n);
    return 0;
}