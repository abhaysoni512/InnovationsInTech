/*
  Recursion :
    - A function that calls itself is called a recursive function.
    - A recursive function must have a base case to stop the recursion.

  Terminlogy :
    - Base case : The condition under which the recursion stops.
    - Recursive case : The condition under which the recursion continues.
    - Stack Space : The amount of memory used by the function calls.
    - Stack Overflow : When the stack space is exceeded, it results in a stack overflow error.
    - Tail Recursion : A recursive function where the recursive call is the last statement in the function.
    - Recurision Tree : A tree that represents the recursive calls made by a function.
*/

#include <bits/stdc++.h>
using namespace std;
auto printN(string_view s,int i, int n){
    if(i > n) return;
    cout << s <<endl;
    printN(s, i+1, n);
    
}

int main(){
    static int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    printN(s,1, n);
    return 0;
}