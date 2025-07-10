#include <iostream>
#include <vector>

using namespace std;
int main(){
    vector <bool> vec{true,false,true,false};
    vec[1] = true;
    cout << vec[1] << endl;
    return 0;
}