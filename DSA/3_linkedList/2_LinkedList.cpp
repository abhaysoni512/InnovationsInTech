#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data{};
    Node *next;
};
class Linkedlist{
private:
    Node *m_first{};
public:
    Linkedlist():m_first(NULL){} // definition
    Linkedlist(const std::vector<int> &arr);     // declaration
    ~Linkedlist();

    void display() const;
    void insert(int index,int x);
    void deleteNode(int index);
    int length();
};
Linkedlist::Linkedlist(const std::vector<int> &arr)
{
    if(arr.empty()){
        cout<<"Array is empty\n";
        m_first = nullptr;
        return;
    }
    m_first = new Node;
    m_first->data=arr[0];
    Node *temp{nullptr}, *last = m_first;

    for(auto i{1};i<arr.size();i++){
        temp = new Node;
        temp->data= arr[i];
        last->next = temp;
        last = temp;
    }
}
Linkedlist::~Linkedlist(){
    if(!m_first){
        cout<<"Linkedlist doesn't exist\n";
        return;
    }
    Node *p = m_first;
    while(p){
        m_first = m_first->next;
        delete p;
        p = m_first;
    }
    cout<<"Linked list deleted successfully\n";
}

void Linkedlist::display() const {
    Node *p = m_first;
    int i = 1;
    while (p)
    {
        cout<<i++<<". element : "<<p->data<<" \n";
        p=p->next;
    }    
}
int main(){
    std::vector arr{11,22,33,44,55};
    Linkedlist l1(arr);
    l1.display();
    return 0;
}