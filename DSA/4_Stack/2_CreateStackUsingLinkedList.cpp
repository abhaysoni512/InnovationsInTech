#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data{};
    struct Node *next{};
};

class Stack{
private:
    Node *top{};
public:
    Stack() = default;
    ~Stack(){
        if(top == NULL ){
            return;
        }
        else{
            Node *t = top;
            while(t){
                top = top->next;
                delete t;
                t = top;
            }
        }
    }
    void push(int x){
        Node *t = new Node;
        t->data = x;
        t->next = top;
        top = t;

    }

    bool pop(){
        if(top == NULL){
            cout<<"Stack is empty\n";
            return false;
        }
        Node *t = top;
        top = top->next;
        delete t;
        return true;
    }

    void Display(){
        Node *t = top;
        while(t){
            cout<<t->data<<"    ";
            t = t->next;
        }
        cout<<endl;
    }
};
int main(){
    Stack st;
    st.push(11);
    st.push(22);
    st.Display();
    st.pop();
    return 0;
}