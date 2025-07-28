/*
Problem Statement:

Given an array `arr` of `N` integers. Given `Q` queries, and in each query given `L` and `R`,
print the sum of array elements from index `L` to `R` (both `L` and `R` inclusive).

Constraints:
1 <= N <= 10^5
1 <= arr[i] <= 10^9
1 <= Q <= 10^5
1 <= L, R <= N
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int arr[N];
int main()
{
    int n;
    cin >> n; // Read size of array
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    while (q--)
    {

        int l, r;
        cin >> l >> r;
        long long sum = 0;
        for (int i = l; i <= r; i++)
        {
            sum += arr[i];
        }
        cout << sum << endl;
    }
    return 0;
}