#include <bits/stdc++.h>
using namespace std;

struct Node {
    unique_ptr<Node> lchild;
    int data;
    unique_ptr<Node> rchild;
    Node() = default;
    Node(int val) : data(val) {}
};

class BinaryTree {
private:
    unique_ptr<Node> m_root;
public:
    BinaryTree() {
        m_root = make_unique<Node>();
    }
    ~BinaryTree() = default; // unique_ptr handles deletion

    void CreateTree() {
        Node *p;
        int x;
        queue<Node *> q;
        cout << "Enter root Node data value : ";
        cin >> x;
        m_root->data = x;
        q.push(m_root.get());
        while (!q.empty()) {
            p = q.front();
            q.pop();
            cout << "Enter value of lchild of " << p->data << " Node: ";
            cin >> x;
            if (x != -1) {
                p->lchild = make_unique<Node>(x);
                q.push(p->lchild.get());
            }
            cout << "Enter value of rchild of " << p->data << " Node: ";
            cin >> x;
            if (x != -1) {
                p->rchild = make_unique<Node>(x);
                q.push(p->rchild.get());
            }
        }
    }
};

int main() {
    BinaryTree b;
    b.CreateTree();
    return 0;
}