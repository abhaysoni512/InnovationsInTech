#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data{};
    Node* next{};
};
class L_Queue{
private:
    Node *m_front{};
    Node *m_rear{};
public:
    L_Queue() = default;
    ~L_Queue(){
        // pass
    }

    bool enqueue(int x){
        //
        Node *t = new Node;
        if(t==NULL) {
            cout<<"Queue is full\n";
            return false;
        } else{
            t->data = x;
            t->next = NULL;
            if(m_front==NULL){
                m_front = m_rear = t;
            }else{
                m_rear->next = t;
                m_rear = t;
                
            }
            return true;
        }
    }

    bool dequeue(){
        if(m_front==NULL){
            cout<<"Queue is empty\n";
            return false;
        }else{
            Node *p =m_front;
            m_front = m_front->next;
            delete p;
            return true;
        }
    }


    void display(){
        if(m_front== NULL){
            cout<<"Queue is empty nothing to print\n";
            return;
        }
        Node *p = m_front;
        while(p!=m_rear){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<m_rear->data<<endl;
    }

};  
int main(){
    L_Queue q;
    q.enqueue(11);
    q.enqueue(22);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();

    return 0;
}