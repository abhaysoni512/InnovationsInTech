#include <bits/stdc++.h>
using namespace std;

int main(){
    // char array
    char s[] = {'A','B','H','A','Y'};
    // add null
    //upercase to lowercase
    char ptr[] = "ABHAY";
    int i = 0;
    while(ptr[i] !='\0'){
        ptr[i] = ptr[i] + 32;
        i++;
    }
    cout<<ptr<<endl;

    return 0;
}