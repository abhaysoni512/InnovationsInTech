#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    //create a map
    map<int , string> m;
    //insert elements into the map
    m[1] = "one";
    m[5] = "five";
    m[3] = "three";
    //
    m.insert({4, "four"});

    map<int , string>::iterator it;
    //print the map
    for(it = m.begin();it != m.end(); it++){
        cout << it->first << " : " << it->second << endl;
    }
}