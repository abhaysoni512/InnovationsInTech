#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
};
using Node_t = struct Node;
template <typename T, auto S>
void CreateLinkedlist(Node_t *&head, std::array<T,S> &arr){
    if(arr.empty()) {
        cout<<"Array is empty\n";
        return;
    }
    head = new Node{arr[0],nullptr};
    Node_t *last = head;
    for(auto i{1};i<S;i++){
        Node_t * temp = new Node{arr[i],nullptr};
        last->next = temp;
        last = temp;
    }
}

void display(Node_t * p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n-----------\n";
}

void countElement(Node_t * p)
{
    if(!p){
        cout<<"No Nodes \n";
        return;
    }
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    cout<<"No of nodes in linkedlist : "<<count<<"\n";
}

void deleteAllNodesLinkedlist(Node_t *&head)
{
    int ctr = 0;
    Node_t *head_storer;
    while (head)
    {
        head_storer = head;
        head = head->next;
        ctr++;
        delete head_storer;  
    }
    cout<<"Deleted "<<ctr<<" Nodes Successfully\n";
}

void SumOfElements(Node_t *head){
    if(!head){
        cout<<"Sum is 0\n ";
    }
    Node_t *ptr = head;
    int sum = 0;
    while(ptr){
        sum+=ptr->data;
        ptr = ptr->next;
    }
    cout<<"Total sum of elements in linkedlist = "<<sum<<endl;
}
void MaxElementInLinkedList(Node_t *head){
    if(!head){
        cout<<"Linked list is empty\n";
        return;
    }
    Node_t *ptr = head;
    int max = INT32_MIN;
    while (ptr)
    {
        /* code */
        if ((ptr->data) > max)
            max = ptr->data;
        ptr = ptr->next;
    }   
    cout<<"Maximum Data : "<<max<<endl;
}
template<typename T>
void SearchElement(Node_t *head,T key){
    if (!head)
    {
        cout << "Linked list is empty\n";
        return;
    }
    Node_t *tmp = head;
    int index = 0;
    while (tmp)
    {
        /* code */
        index++;
        if(tmp->data == key){
            cout<<"Element found at node "<<index<<" node\n";
            return;
        }
        tmp = tmp->next;
    }
    cout<<"Element not found\n"; 
}

// jab bhi original linked list modify krni h pass by reference kro
void InsertNode(Node_t *&head, int index, int data)
{
    //                         ----------       ----------
    // Node Structutre head-> |   |    |  -->  |   |    |
    //                         |   |    |       |   |    |
    //                         ----------       ----------    
    // if we want to insert at head node i.e. index = 0
    if (index == 0){
        // s1 create a new node
        Node_t *t = new Node_t;
        // s2 insert data
        t->data = data;
        // s3 newly create node points to existing linkedlist head node
        t->next = head;
        // s4 head should point to newly Create node 
        head = t;
    }
    else{
        // s1 create a new node
        Node_t *t = new Node_t;

        // s2 insert data
        t->data = data;

        // s3 point p pointer to head
        Node_t *p = head;

        // s3 iterate
        for(int i=0;i<index-1;i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;

    }
}
// Insert on sorted data linked list without mentioning index
void InsertedOnSortedData(Node_t *&head, int key){
    // we will use two pointers
    auto p = head;
    Node_t * q = NULL;
    while(p != NULL && key > p->data){
        q = p;
        p = p->next;
    }
    Node_t *t = new Node_t;
    t->data = key;
    t->next= q->next;
    q->next = t;
}
void DeleteANode(Node_t *&head, int index = 1){
    if(index<1){
        cout<<"Invalide index: "<<index<<endl;
        return;
    }
    if(index == 1){
        auto p = head;
        head = p->next;
        delete p;
    }
    else{
        auto p = head;
        Node_t * q = NULL;
        for(int i = 1;i<index ;i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p; 
    }
}

void IslinkedListSorted(Node_t *head){
    /*
    Node_t *prev = head;
    Node_t *curr = head->next;

    while (curr)
    {   
        if(head->data > prev->data){
            cout << "LinkedList is not sorted\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout<<"Linked is sorted\n";
    */
// Another way;
int x = -65536;
while(head){
    if(head->data<x){
        cout << "LinkedList is not sorted\n";
        return;
    }
    x = head->data;
    head= head->next;
}
cout << "Linked is sorted\n";
}

void RemoveDuplicateElements(Node_t * &head){
    Node_t *p = head;
    Node   *q = head->next;
    while(q){
        if(p->data == q->data){
            p->next = q->next;
            delete q;
            q = p->next;
        }else{
            p = q;
            q = q->next;
        }
    }
}

void ReverseLinkedList(Node_t* &head){
    Node_t *p = head; // head pointer
    Node_t *q = NULL; // trailing pointer
    Node_t *r = NULL; // last pointer
    while(p){
        // s1 Sliding 
        r = q;
        q = p;
        p = p->next;

        // s2 change the link
        q->next = r;
    }
    // s3 head should point to origiginal's last link note this is q not p , p to null ko point krega last m
    head = q;
}

void Concatenate(Node_t * &head1, Node_t * &head2){
    Node_t *p = head1;
    while (p->next !=NULL)
    {
        p = p->next;
    }
    p->next  = head2;
    
}

void MergingTwoLinkedList(Node_t * &first, Node_t * &second){
    Node_t *third = NULL,*last = NULL;
    if(first->data<second->data){
        third = last = first;
        first = first->next;
    }
    else{
        third = last = second;
        second = second->next;
    }
    while (first && second){
        if(first->data<= second->data){
            last->next = first;
            last = first;
            first = first->next;
        }
        else{
            last->next = second;
            last = second;
            second = second->next;
        }
    }
    if (first != NULL)
        last->next = first;
    else
    {
        last->next = second;
    }
    display(third);     
}

bool IsLoopLinkedlist(Node_t * &head){
    Node *p,*q;
    p = q = head;

    do{
        p = p->next;
        q = q->next;
        q = q !=NULL? q->next : NULL;
    }while((p&&q) && (p!=q) );
    if(p==q){
        cout<<"Loop found\n";
        return true;
    }else{
        cout<<"Loop not found i.e. linear\n";
        return false;
    }
}

int main()
{

    Node_t *head;
    std::array arr {11,22,22,33,33,33,44,55};

    // create
    CreateLinkedlist(head, arr);
    display(head);

    // counting
    countElement(head);

    //sum
    SumOfElements(head);

    //maxData
    MaxElementInLinkedList(head);

    // Searching
    cout<<"Enter Key = ";
    int key;
    cin>>key;
    cout<<key<<endl;
    SearchElement(head,key);

    // Insert at 0th node (befor )
    InsertNode(head,0,1);
    display(head);

    // insert after 4 th node
    InsertNode(head, 4, 40);
    display(head);

    // insert on a sorted array
    InsertedOnSortedData(head, 80);
    display(head);


    // delete 1st node:
    DeleteANode(head,1);
    display(head);

    // delete 4th node:
    DeleteANode(head,4);
    display(head);

    // Is a linked list sorted or not
    IslinkedListSorted(head);
    
    // RemoveDuplicare element
    RemoveDuplicateElements(head);
    display(head);

    // Reverse linked List
    ReverseLinkedList(head);
    display(head);

    // Create a new linkedlist
    Node_t *head1 = nullptr;
    std::array arr1 {1,2,3,4,5};
    CreateLinkedlist(head1,arr1);

    // Concatnate two Linked list
    Concatenate(head,head1);
    display(head);

    // Merging two linked list
    Node_t *head2 = nullptr;
    std::array arr2{1, 3, 5, 7};
    CreateLinkedlist(head2,arr2);
    Node_t *head3 = nullptr;
    std::array arr3{2, 4, 6, 8};
    CreateLinkedlist(head3, arr3);

    MergingTwoLinkedList(head2,head3);

    IsLoopLinkedlist(head2);
    
    deleteAllNodesLinkedlist(head);

    return 0;
}