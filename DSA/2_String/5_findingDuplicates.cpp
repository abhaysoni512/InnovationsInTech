#include <bits/stdc++.h>
using namespace std;
void duplicateArrayM1(string str){
    for(int i = 0 ;str[i]!='\0';i++){
        int count = 1;
        for(int j = i+1;str[j]!='\0';j++){
            if(str[i]==str[j]&& str[i]!='0'){
              count++;
              str[j]='0';  
            }    
        }
        if(count>1){
            cout << str[i] << " repeated " << count << " times\n";
        }
    }
}
void duplicateArrayM2(string_view str){
    std::array<int,26> Hass{};
    for(int i = 0;str[i]!='\0';i++){
        Hass[str[i]-97]++;
    }
    for(int i{0};i<26;i++){
        if(Hass[i]>1){
            cout<<char(i+97)<<" repeated "<<Hass[i]<<" times\n";
        }
    }
}
void duplicateArrayM3(string str){
    for(int i{0};str[i]!='\0';i++){
        int count = 1;
        for(int j{i+1};str[j]!='\0';j++){
            if(str[i]&&str[j]<<2) {
                count++;
                str[j] = '0';
            }
        }
        cout<<str[i]<< " repeated "<<count<<" times\n";
    }
}
int main()
{
    string str{"abhayab"};
    duplicateArrayM1(str); // using brute force method

    cout<<"-----------------------------\n";
    duplicateArrayM2(str);
    cout << "-----------------------------\n";

    duplicateArrayM3(str);

    return 0;
}