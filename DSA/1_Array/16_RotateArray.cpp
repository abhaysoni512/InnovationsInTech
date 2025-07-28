#include <bits/stdc++.h>
using namespace std;

template <typename T, auto S>
void InsertElementSpecial(std::array<T, S> &arr,T key,int filledEle)
{

    int i = filledEle-1; //filled 9 means arr[8] is filled arr[9] is empty
    while(arr[i]>=key){
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = key;
}

int main()
{
    std::array<int, 10> arr{11, 22, 33, 44, 55, 66, 77, 88, 99};

    cout << "Original ele : ";
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << "\n";

    InsertElementSpecial(arr,90,9);
    cout << "Insert element in sorted array : ";
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << "\n";

    return 0;
}