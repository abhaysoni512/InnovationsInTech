#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.emplace_back(2);
    cout << v1[0] << " " << v1[1] << endl;
    vector<pair<int, int>> v2;
    v2.emplace_back(3, 4);
    cout << v2[0].first << " " << v2[0].second << endl;

    vector<int> v3(5, 10); // 5 elements, each initialized to 10

    // Using iterator
    vector<int>::iterator it = v3.begin();
    cout << "\nUsing iterator: v3 = ";
    for (; it != v3.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    // Using range-based for loop
    cout << "Using range-based for loop: v3 = ";
    for (auto item : v3)
    {
        cout << item << " ";
    }
    cout << endl;
    cout << endl;
    // erase
    vector v4 = {1, 2, 3, 4, 5};
    cout << "v4 = ";
    for (auto item : v4)
    {
        cout << item << " ";
    }
    cout << endl;
    // v4.erase(2); // erase the third element, wont work
    v4.erase(v4.begin() + 2); // erase the third element
    cout << "After erase: v4 = ";
    for (auto item : v4)
    {
        cout << item << " ";
    }
    cout << endl;

    // erase in range
    vector<int> v5 = {1, 2, 3, 4, 5};
    cout << "v5 = ";
    for (auto item : v5)
    {
        cout << item << " ";
    }
    cout << endl;
    v5.erase(v5.begin() + 1, v5.begin() + 3); // erase the second and third elements
    cout << "After erase in range: v5 = ";
    for (auto item : v5)
    {
        cout << item << " ";
    }
    cout << endl;
    cout << endl;

    // insert
    vector<int> v6 = {1, 2, 3, 4, 5};
    cout << "v6 = ";
    for (auto item : v6)
    {
        cout << item << " ";
    }
    cout << endl;
    v6.insert(v6.begin() + 1, 10); // insert 10 at the 2nd position
    cout << "After insert: v6 = ";
    for (const auto &item : v6)
    {
        cout << item << " ";
    }
    cout << endl;
    // insert in range
    v6.insert(v6.begin() + 1, 2, 20); // insert 20 two times at the 2rd position // 1 20 20 10 2 3 4 5
    cout << "After insert in range: v6 = ";
    for (const auto &item : v6)
    {
        cout << item << " ";
    }
    cout << endl;
}