#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
long long arr[MAXN];
long long prefix[MAXN]; // To store prefix sums

int main()
{
    int n, q;
    cin >> n >> q; // Read size of array and number of queries

    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i]; // Compute prefix sum
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << endl; // O(1) sum query
    }

    return 0;
}
