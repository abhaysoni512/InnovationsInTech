#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v{4, 32, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // sort
    sort(v.begin(), v.end()); // sort in ascending order
    cout << "Sorted vector: ";
    for (auto item : v)
    {
        cout << item << " ";
    }
    cout << endl;

    // sort a portion of the vector

    vector<int> v1{4, 32, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sort(v1.begin(), v1.begin() + 4); // sort first 4 elements
    cout << "Sorted vector: ";
    for (auto item : v1)
    {
        cout << item << " ";
    }
    cout << endl;

    // sort in descending order
    sort(v1.begin(), v1.end(), greater<int>());
    cout << "Sorted vector in descending order: ";
    for (auto item : v1)
    {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}