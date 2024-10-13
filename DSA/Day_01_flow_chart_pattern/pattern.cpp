// C++ code here
#include<iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter no of rows:  ";
    cin>>n;
    int i,j=1,temp;
    char c='A';
    for(i=1;i<=n;i++){     
        temp=n+1-i;
        for(j=1;j<=i;j++){
            cout<<char('A'+temp+j-2)<<" ";
        }
        cout<<endl;
    } 
    return 0;
}