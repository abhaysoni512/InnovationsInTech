#include <bits/stdc++.h>
using namespace std;
// global vector

int main(){
    std::array arr{6,3,8,10,16,7,5,2,9,14,4};
    std::vector<int> H(*max_element(arr.begin(),arr.end()) +1 ,0);
    
    cout<<"Sum = ";
    int sum = 0;
    cin>>sum;
    cout<<sum <<"\n";
    for(int i{0};i<arr.size();i++){
        if(H[sum-arr[i]]!=0){
            cout << "Pair found: " << sum - arr[i] << " + " << arr[i]<< " = " << sum << endl;
        }
        H[arr[i]]++;
    }

    //for sorted array 
    
    return 0;
}