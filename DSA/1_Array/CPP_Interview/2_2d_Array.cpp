#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 1st way :
    int A1[3][4];
    int sum = 0;
    for (int i{}; i < 3; i++)
    {
        for (int j{}; j < 4; j++)
        {
            A1[i][j] = ++sum;
        }
    }

    // 2nd way : Array of integer pointer
    int *A2[3];
    for (int i{}; i < 3; i++)
    {
        A2[i] = new int[4];
    }

    for (int i{}; i < 3; i++)
    {
        delete[] A2[i];
    }

    //  3rd way: Using double pointer
    int **ptr;
    ptr = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        ptr[i] = new int[4];
    }

    // deleting

    // s1 delete row first
    for (int i = 0; i < 3; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;

    return 0;
}