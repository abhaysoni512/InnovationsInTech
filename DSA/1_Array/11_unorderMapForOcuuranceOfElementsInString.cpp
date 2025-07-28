#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    // fetch
    unordered_map<char, int> mpp;
    for (int i{0}; i < s.size(); i++)
    {
        // o(1) for good case // o(n) for worst case
        mpp[s[i]]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        cout << c << " apppears " << mpp[c] << " times\n";
    }
    return 0;
}