#include <bits/stdc++.h>
using namespace std;

//Constraints
// 1 <= n <= 10^5
// 1 <= arr[i] <= 10^5
// 1 <= q <= 10^5

const int MAX_SIZE = 1e7 + 1; // Maximum size of the array
int hashTable[MAX_SIZE] = {0}; // Initialize hash table with zeros
int main(){
    int n;
    cout << "Enter size of array : \n";
    cin >> n;
    if (n <= 0) {
        cout << "Array size must be positive." << endl;
        return 1;
    }
    int arr[n];
    cout << "\nEnter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Build the hash table
    for(int i =0 ; i < n; i++) {
        if (arr[i] < 0 || arr[i] >= MAX_SIZE) {
            cout << "\nElement out of bounds: " << arr[i] << endl;
            return 1; // Exit if an element is out of bounds
        }
        hashTable[arr[i]]++;
    }

    cout << "\nEnter no of queries: \n";
    int q;
    cin >> q;
    while (q--) {
        int no;
        cout << "Enter element to search: ";
        cin >> no;
        cout << "Element " << no << " occurs " << hashTable[no] << " times." << endl;
    };
    return 0;
}