#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Binary Search
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    bool result = binary_search(arr, arr + n, 5);
    if (result)
    {
        cout << "Element found" << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    // lower_bound is used to find the first element which is greater than or equal to the given element

    int index = lower_bound(arr, arr + n, 2) - arr; // 1
    cout << "Lower bound index of 2: " << index << endl;
    // if element is not found either it will return next greater element or end + 1 th index
    index = lower_bound(arr, arr + n, 10) - arr; // 9
    cout << "Lower bound index of 10: " << index << endl;

    // application of binary search
    int arr2[] = {1, 2, 2, 2, 2, 3, 5, 6, 7, 8, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    // check if element X first occurence if it is present then return the index else -1
    int X;
    cin >> X;
    int index1 = lower_bound(arr2, arr2 + n2, X) - arr2;
    if (index1 == n2 || arr2[index1] != X)
    {
        cout << "-1" << endl; // o(log n)
    }
    else
    {
        cout << "First occurence of " << X << " is at index: " << index1 << endl;
    }
    int x1;
    cin >> x1;
    // check if element X last occurence if it is present then return the index else -1
    int index2 = upper_bound(arr2, arr2 + n2, x1) - arr2 - 1;
    if (index2 == -1 || arr2[index2] != x1)
    {
        cout << "-1" << endl; // o(log n)
    }
    else
    {
        cout << "Last occurence of " << X << " is at index: " << index2 << endl;
    }

    /*

    when we use intilizer_list we can use begin and end

    // Binary search is used to find the element in a sorted array
    bool result = binary_search(arr.begin(), arr.end(), 5);
    if(result){
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }

    // lower_bound is used to find the first element which is greater than or equal to the given element

    int index = lower_bound(arr.begin(), arr.end(),2) - arr.begin(); //1
    cout << "Lower bound index of 2: " << index << endl;
    //if element is not found either it will return next greater element or end + 1 th index
    index = lower_bound(arr.begin(), arr.end(), 10) - arr.begin(); //9
    */
    return 0;
}