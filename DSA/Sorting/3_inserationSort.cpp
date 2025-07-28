#include <bits/stdc++.h>
using namespace std;
template <typename T, auto n>
void bubble_sort(array<T, n> &arr)
{
    bool check = false;
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                check = true;
            }
        }
        if (!check)
            break;
    }
}
int main()
{
    array arr{13, 46, 24, 52, 20, 9};
    for (const auto &ele : arr)
    {
        cout << "Element in array: " << ele << " \n";
    }
    cout << "\n";
    bubble_sort(arr);
    for (const auto &ele : arr)
    {
        cout << "Element in array after selection sort: " << ele << " \n";
    }
    cout << "\n";
    return 0;
}