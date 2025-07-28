#include <bits/stdc++.h>
using namespace std;
bool validString(string_view str){
    for(int i{0};str[i]!='\0';i++){
       if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122 )|| (str[i]>=48 && str[i]<= 57)) {
            continue;
       }
       else{
            return false;
       }
    }
    return true;
}
int main(){
    std::string str = "Abhay123";
    
    cout<<validString(str)<<endl;
    return 0;
}