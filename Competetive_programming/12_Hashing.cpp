#include <bits/stdc++.h>
const int N = 1e7 + 5;
int Hash[N];
using namespace std;
int main()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        Hash[arr[i]]++;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        cout << Hash[n] << endl;
    }
    return 0;
}