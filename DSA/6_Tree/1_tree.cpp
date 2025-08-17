// C++ code here
#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* lchild{};
    int data;
    Node* rchild{};
    Node() = default;
    Node(int val) : data(val), lchild(nullptr), rchild(nullptr) {}
   

};

// C++ code here : Create a binary tree node structure
class BinaryTree  
{
private:
    Node *m_root;
    void preorder(Node *node){
        if(node == nullptr) {
            return;
        }
        cout<<node->data<<" ";
        preorder(node->lchild);
        preorder(node->rchild);
    
    }
    void inorder(Node *node){
        if(node == nullptr) {
            return;
        }
        
        inorder(node->lchild);
        cout<<node->data<<" ";
        inorder(node->rchild);
    
    }
    void postorder(Node *node){
        if(node == nullptr) {
            return;
        }
        postorder(node->lchild);
        postorder(node->rchild);
        cout<<node->data<<" ";
    
    }
    void preOrderWR(Node *t){
        // we will use stack
        // there are two 
        
        // if Node * t is not null 
        // we will print value , push current node on stack and move to left
        
        // if Node * t is null
        // we will pop the address freom stack , go to the node and wont print to right child

        stack<Node *> st;
        
        while (t!=NULL || !st.empty())
        {
            if(t!=NULL){
                cout<<t->data<<" ";
                st.push(t);
                t = t->lchild;
            }else{
                t = st.top();
                st.pop();
                t = t->rchild;
            }
        }
        cout<<endl;
    }

    void inOrderWR(Node *t){
        stack <Node *> st;
        while(t!=NULL || !st.empty()){
            if(t!=NULL){
                st.push(t);
                t= t->lchild;
            }else{
                t = st.top();
                st.pop();
                t= t->rchild;
            }
        }
        cout<<endl;
    }
public:
    BinaryTree(){
        m_root = new Node();
    }
    ~BinaryTree(){
        // Need to think
        delete m_root;
    }

    void CreateTree(){
        /*
            @details : p is used to track current Node.
                       t is used to create New Node.
        */
        Node *p, *t;
        int x;
        queue<Node *> q;
        cout<<"Enter root Node data value : ";
        cin>>x;
        m_root->data = x;
        q.push(m_root);
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            cout<<"Enter value of lchild of "<<p->data<<" Node: ";
            cin>>x;
            if(x!=-1){
                // l child
                t = new Node(x);
                p->lchild = t;
                q.push(t);
            }
            cout<<"Enter value of rchild of "<<p->data<<" Node: ";
            cin>>x;
            if(x!=-1){
                // l child
                t = new Node(x);
                p->rchild = t;
                q.push(t);
            }
            
        }
        
    }

    // preorder
    void preorderNode(){
        preorder(m_root);
    }

    // inorder
    void inorderNode(){
        inorder(m_root);
    }

    // postorder
    void postorderNode(){
        postorder(m_root);
    }
    
    void preOrderWithoutRecursion(){
        preOrderWR(m_root);
    }

    void inOrderWithoutRecursion(){
        inOrderWR(m_root);
    }
};


int main() {
    //      1
    //  2        3
    // 4  5     6  7
    BinaryTree b;
    b.CreateTree();
    b.preorderNode();
    cout<<endl;
    b.inorderNode();
    cout<<endl;
    b.postorderNode();
    cout<<endl;
    cout<<"Without recursion printing preorder: ";
    b.preOrderWithoutRecursion();
    cout<<"Without recursion printing inorder: ";
    b.inOrderWithoutRecursion();
    return 0;
}