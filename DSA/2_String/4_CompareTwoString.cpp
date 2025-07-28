#include <bits/stdc++.h>
using namespace std;
void CompareString(string_view str1,string_view str2){
    if(str1.length()!=str2.length()){
        cout<<"Str1.. is not same as str2\n";
    }else{
        int i ;
        for(i=0;str1[i]!='\0';i++){
            if(str1[i]!=str2[i]) {
                cout << "Str1 is not same as str2\n";
                break;
            }
        }
            if(i == str1.length())
                cout << "Str1 is same as str2\n";
        }
}
int main(){
    string str1 = "Abhay";
    string str2 = "Abhay";
    CompareString(str1,str2);
    return 0;
}