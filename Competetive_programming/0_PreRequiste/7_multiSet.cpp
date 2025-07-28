#include <bits/stdc++.h>
using namespace std;

int main()
{
    // sorted set but it allows duplicates
    multiset<int> ms = {1, 2, 2, 2, 3, 4, 5};
    cout << "ms.count(2) = " << ms.count(2) << endl; // 3

    ms.insert(6);
    ms.insert(6);
    ms.insert(6);

    cout << "After insert: ms = ";
    for (auto item : ms)
    {
        cout << item << " ";
    }
    cout << endl;

    // erase elements/element
    ms.erase(6);
    cout << "After erase: ms = ";
    for (auto item : ms)
    {
        cout << item << " ";
    }
    cout << endl;

    // want to errase single occurance of 6

    ms.insert(6);
    ms.insert(6);
    ms.insert(6);

    ms.erase(ms.find(6)); // erase only one occurance of 6
    cout << "After erase single occurance: ms = ";
    for (auto item : ms)
    {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}