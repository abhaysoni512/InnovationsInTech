#include <bits/stdc++.h>
using namespace std;
void Nameprint(string_view name,int st, int times){
    if (st > times) return ;
    cout << name <<endl ;
    st++;
    Nameprint(name, st, times);
}
int main(){
    string name {"Abhay"};
    Nameprint(name,1, 5);

    return 0;
}