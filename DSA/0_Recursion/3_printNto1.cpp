#include <bits/stdc++.h>
using namespace std;
void f(int i, const int &N)
{
    if(i>N) return;
    f(++i,N);
    cout << --i << endl;
}
int main(){
    int N;
    cin >> N;
    f(1,N);
    return 0;
}