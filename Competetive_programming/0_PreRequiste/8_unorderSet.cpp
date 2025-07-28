#include <bits/stdc++.h>
using namespace std;

int main()
{
    // store in random order but unique elements
    // unordered_set is implemented as a hash table
    // it is not sorted
    // it is not random access
    // it provides O(1) time complexity for insertion, deletion, and search
    // at worst O(n) time complexity for insertion, deletion, and search

    unordered_set<int> us = {5, 2, 3, 1, 4};
    return 0;
}