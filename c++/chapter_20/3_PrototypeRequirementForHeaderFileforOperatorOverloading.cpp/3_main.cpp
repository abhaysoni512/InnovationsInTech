#include <bits/stdc++.h>
#include "3_Header.h"
using namespace std;
cents operator+(const cents &c1, const int &i){
    return cents{c1.getCents()+i};
}
int main(){
    cents c1{15};
    cout << (c1+10).getCents()<<endl;
    return 0;
}