#include <iostream>
using namespace std;
void doNotReturn(){

}
int returnfive(){
    return 5;
}
int main(){
    cout<<"five: "<<returnfive()<<endl; //cout must have a contant/value to print 
    //cout<<"Do not return: "<<doNotReturn()<<endl;
}