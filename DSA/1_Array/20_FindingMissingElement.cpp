#include <bits/stdc++.h>
using namespace std;
template <typename T, auto S>
void MissingElement(std::array<T,S>&arr){
    int sumofnaturalno = (arr[S - 1] * (arr[S-1] +1))/2;
    int sum = 0;
    for(auto const &ele: arr){
        sum+=ele;
    } 
    cout<<"Missing element : "<<sumofnaturalno-sum<<endl;
}
template <typename T, auto S>
void MissingElement1(std::array<T, S> &arr1)
{
    int diff = arr1[0];
    for(int i{0};i<S;i++){
        if(arr1[i]-i!=diff){
            cout<<"Missing Element : "<< diff+i<<endl;
            break;
        }
    }
}
template <typename T, auto S>
void MissingMultipleElement(std::array<T, S> &arr2){
    int diff = arr2[0];
    std::vector<int> missingElement{};
    for(int i{0};i<S;i++){
        if(arr2[i]-i !=diff){
            int noOfMissingElement = arr2[i] - i - diff;
            while(noOfMissingElement){
                missingElement.push_back(diff+i);
                diff++;
                noOfMissingElement--;
            }
        }
    }
    cout << "Elements missing : ";
    for (const auto &ele : missingElement)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
}

int main()
{
    std::array arr{1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13};
    MissingElement(arr);

    std::array arr1{6, 7, 8, 9, 10, 11, 13, 14, 15};
    MissingElement1(arr1);

    // one more thing it work for natural number too starting from 1
    MissingElement1(arr);

    std::array arr2{6, 7, 8, 9, 10, 11, 13, 16};
    MissingMultipleElement(arr2);

    return 0;
}