#include <bits/stdc++.h>
using namespace std;

int main()
{
    // store in form of key value pair
    // it is implemented as a balanced binary search tree
    // it is sorted in ascending order by default (sorted map)
    // it is not random access
    // it provides O(log n) time complexity for insertion, deletion, and search
    // it is not contiguous in memory
    // key is unique and value can be duplicate

    map<int, int> m = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << "m = ";
    for (auto item : m)
    {
        cout << item.first << " " << item.second << endl;
    }
    cout << endl;

    // insert
    m.insert({5, 6}); // on key 5 store value 6
    m[6] = 7;         // on key 6 store value 7
    cout << "After insert: m = ";
    for (auto item : m)
    {
        cout << item.first << " " << item.second << endl;
    }
    cout << endl;

    // fine key's value
    auto it = m.find(3);
    if (it != m.end())
    {
        cout << "Found: " << it->first << " " << it->second << endl;
    }
    else
    {
        // if the element is not found in the map it will return end() means last element ke baad
        cout << "Not found" << endl;
    }
    return 0;
}