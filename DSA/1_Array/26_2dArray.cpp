#include <bits/stdc++.h>
using namespace std;

int main(){
    int A[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    for (int i{}; i < 3; i++)
    {
        for (int j{}; j < 4; j++)
        {
            cout << A[i][j] << "    ";
        }
        cout << endl;
    }
    cout << endl;
    // m2 
    int *B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];
    for (int i{}; i < 3; i++)
    {
        for (int j{}; j < 4; j++)
        {
            cout << B[i][j] << "    ";
        }
        cout << endl;
    }
    cout << endl;

    int **C;
    C = new int*[3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];
    for (int i{}; i < 3; i++)
    {
        for (int j{}; j < 4; j++)
        {
            cout << C[i][j] << "    ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}