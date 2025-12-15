#include <bits/stdc++.h>
using namespace std;

int main(){
    int *ptr = new int[5];
    for (int i = 0;i<5;i++){
        ptr[i] = i;
    }

    int *q = new int[10];

    memcpy(q,ptr,5 * sizeof(int));

    delete []ptr;
    ptr = q;
    q = NULL;

    // delete ptr
    delete []ptr;

    return 0;
}