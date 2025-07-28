#include <bits/stdc++.h>
using namespace std;

int main(){
    std::array arr{6,3,8,10,16,7,5,2,9,14};
    cout<<"Enter sum value = ";
    int k;
    cin>>k;
    cout<<"k = "<<k<<"\n";
    int i = 0, j = arr.size() - 1;
    while(i<j){
        if(arr[i] + arr[j] == k) {
            cout<<"arr["<<i<<"] : "<<arr[i]<<" + arr["<<j<<"] : "<<arr[j]<<" = "<<k<<endl;
            i++;
            j--;
        } else if(arr[i] + arr[j] < k) {
            i++;
        } else {
            j--;
        }
    }
    return 0;
}