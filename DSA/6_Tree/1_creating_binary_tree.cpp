// C++ code here
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *lchild{};
    int data;
    Node *rchild{};
    Node() = default;
    Node(int val) : data(val), lchild(nullptr), rchild(nullptr) {}
};
