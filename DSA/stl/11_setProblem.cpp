#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<string> se;
    int n;

    cout << "Enter no of string to check: ";
    cin >> n;
    string s{};

    for (int i{}; i < n; i++)
    {
        cout << "Enter String : ";
        cin >> s;
        se.insert(s);
    }
    cout << "\n";
    for (const auto &str : se)
    {
        cout<<str<<"\n";
    }

    return 0;
}