#include <bits/stdc++.h>
using namespace std;
void IsAnagram(string_view str1,string_view str2){
    if(str1.length()!=str2.length()){
        cout<<str1<<" is not a Anagram with "<<str2<<endl;
        return;
    }
    /*
    vector<int> Hass1(256,0);
    vector<int> Hass2(256, 0);

    for(int i{0};i<str1.length();i++){
        Hass1[str1[i]]++;
        Hass2[str2[i]]++;
    }

    for (int i{0}; i < 256; i++){
        if (Hass1[i] != Hass2[i]){
            cout << str1 << " is not a Anagram with " << str2 << endl;
            return;
        }
    }
    */

    // we can optimise above :
    vector<int> Hass(256,0);

    for (int i{0}; i < str1.length(); i++){
        Hass[str1[i]]++;
        Hass[str2[i]]--;
    }
    for (int i{0}; i < 256; i++){
        if(Hass[i]!=0){
            cout << str1 << " is not a Anagram with " << str2 << endl;
            return;
        }
    }

    cout << str1 << " is a Anagram with " << str2 << endl;
}
int main(){
    string str1{"decimml"};
    string str2{"medical"};

    IsAnagram(str1,str2);
    return 0;
}