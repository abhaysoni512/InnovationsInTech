#include <bits/stdc++.h>
using namespace std;

int main()
{

    // The main difference between ordered map or unordered map is :
    // 1. implementaiton : tree nahi hash map use hota h
    // 2. time complexity : time complexity :- o(1) but due to collosion it may cause o(n)
    // 3. valid key datatypes : means primitive data type ko key m use kr skte h but suppose kro map/vector ye sub ko key ke trh use kre to code fat jayga

    unordered_map<int, string> m;
    m[1] = "abc"; // Insertion takes o(logn)
    m[3] = "xyz";
    m[2] = "pqr";
    m.insert({4, "sdf"});
    m.insert({4, "xxx"}); // still showing sdf
    m[4] = "xxx";         // here it will change
    unordered_map<int, string>::iterator it1 = m.begin();
    for (; it1 != m.end(); it1++)
    {
        cout << it1->first << " <-> " << it1->second << "\n";
    }
    cout << endl;

    // it will store value of m
    for (const auto &it : m)
    {
        cout << it.first << " <-> " << it.second << " \n";
    }
    cout << endl;

    // how to find key occurs or not
    auto it = m.find(3); // log(n) : self balancing tree
    if (it != m.end())
    {
        cout << "Key three found : " << it->first << " <-> " << it->second << endl;
    }

    // erasing
    m.erase(3); // log(n)
    // or we can erase like
    auto it3 = m.find(4);
    if (it3 != m.end())
        m.erase(it3);
    // it will store value of m
    for (const auto &it : m)
    {
        cout << it.first << " <-> " << it.second << " \n";
    }
    cout << endl;

    return 0;
}