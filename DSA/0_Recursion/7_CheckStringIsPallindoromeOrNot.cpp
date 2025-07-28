#include <iostream>
using namespace std;
bool IsPallindrome(string &s, size_t index =0){
    size_t size = ssize(s);
    if(index >= size/2) return true;     // A B C A : 0 1 2 3.   
    if(s[index]!=s[size-1-index]) return false;
    else{
      return IsPallindrome(s,index+1);
    }
}


int main()
{
    string s;
    cout<<"Enter a String : \n";
    cin>>s;
    if(!IsPallindrome(s,0)){
        cout<<s<<" isn't a pallindrome\n";
    }else{
        cout << s << " is a pallindrome\n";
    }

    return 0;
}