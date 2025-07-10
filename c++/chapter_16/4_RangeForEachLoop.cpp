/*
    Range-based for loops:
        for (element_declaration : array_object)
                statement;
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector arr{0, 2, 3, 4, 5};
    for(const auto &num : arr){
        cout << num << " "<<endl;
    }
    //This for loop will change the value of the element in the array
    return 0;
}

//working : num is a copy of the element in the array
//if you want to change the value of the element in the array, use a reference
//for(int &num : arr) will change the value of the element in the array