#include <bits/stdc++.h>
using namespace std;
void f(int i, int N){
    if(i<1) return ;
    f(--i,N);
    cout<<++i<<endl;

}
int main(){
    f(5,5);
    return 0;
}