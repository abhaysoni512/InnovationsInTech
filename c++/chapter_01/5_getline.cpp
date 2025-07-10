#include <iostream>
using namespace std;
int main(){
 string fullname;
 cout<< "Please enter your name: ";
 cin>>fullname;
//  getline(cin,fullname);
 cout<< "Hello, " << fullname << "!" << endl;
 return 0;
}