#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data{};
    Node *next{};
};

class CircularLinkedlist{
private:
    Node *m_head;
public:
    CircularLinkedlist(const std::vector<int> &arr){
        if (arr.empty())
        {
            cout << "Array is empty\n";
            m_head = nullptr;
            return;
        }
        m_head = new Node;
        m_head->data = arr[0];
        Node *temp{nullptr}, *last = m_head;

        for (auto i{1}; i < arr.size(); i++)
        {
            temp = new Node;
            temp->data = arr[i];
            last->next = temp;
            last = temp;
        }
        last->next = m_head;
    }
    ~CircularLinkedlist(){
        if (!m_head)
        {
            cout << "Circular Linkedlist doesn't exist\n";
            return;
        }
        Node *p = m_head->next;
        while(p!= m_head){
            Node *temp = p;
            p = p->next;
            delete temp;
        }
        delete m_head;
        m_head = NULL;
        cout << "Circular Linked list deleted successfully\n";
    }
    void display() const{
        Node *t = m_head->next;
        cout<<m_head->data;
        while (t!=m_head)
        {
            /* code */
            cout<<"-----"<<t->data;
            t = t->next;
        }
        cout<<endl;
    }

    void InsertIntoLinkedList(int index,int value){
        // case 1 inseting after 1st onwards linkedlist
        if(index!=0){
            Node *t;
            Node *p = m_head;
            for(int i=0;i<index-1;i++){
                p = p->next; 
            }
            t = new Node{value,p->next};
            p->next = t;
        }
        else{
            Node *t;
            Node *p = m_head->next,*last;    //mistake hui mere se loop chlga hi
            t = new Node{value,m_head};
            while(p!=m_head){
                last =p; 
                p = p->next;
            }
            last->next = t;
            m_head =t; 
        }
    }

    void DeleteNode(int index){
        if(index<1){
            cout<<"Enter valid index\n";
            return;
        }
        if(index!=1){
            Node *cpd = m_head;
            Node *trailingPointer = NULL;
            for(int i = 0;i<index-1;i++){
                trailingPointer = cpd;
                cpd = cpd->next;
            }
            trailingPointer->next = cpd->next;
            delete cpd;
        }
        else{
            Node *t = m_head->next;
            Node *last_node_pointer = NULL;
            while(t != m_head){
                last_node_pointer = t;
                t = t->next;
            }
            last_node_pointer->next = m_head->next;
            delete m_head;
            m_head = last_node_pointer->next;
        }
    }
};

int main(){

    CircularLinkedlist c1{{11,22,33,44,55}};
    c1.display();
    c1.InsertIntoLinkedList(5,66);
    c1.display();

    // Insert at index 0
    c1.InsertIntoLinkedList(0,1);
    c1.display();
    // c1.DeleteNode(2);
    // c1.display();

    c1.DeleteNode(1);
    c1.display();
    return 0;
}