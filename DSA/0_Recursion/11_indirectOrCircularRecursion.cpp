#include <bits/stdc++.h>
using namespace std;
void funB(int);
void funA(int n){
    if(n){
        cout<<n<<" ";
        funB(n-1);
    }
}
void funB(int n){
    if(n>1){
        cout << n << " ";
        funA(n/2);
    }
}
int main(){
    int x = 20;
    funA(20);
    return 0;
}