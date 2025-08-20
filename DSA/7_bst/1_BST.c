#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;

void Insert(int key){
   
    struct Node *t = root;

    // Take a trailing pointer 
    struct Node *r = NULL;

    // pointer p for creating new Node
    struct Node *p = NULL;



    if(root==NULL){
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = NULL;
        p->rchild = NULL;
        root = p;
        return;
    }

    while (t!=NULL)
    {
        // trailing pointer 
        r = t;

        // Means Node already exist
        if(t->data== key)
            return;
        
        else if(key>t->data)
            t = t->rchild;
        
        else
            t = t->lchild;

    }

    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = NULL;
    p->rchild = NULL;

    if(p->data > r->data){
        r->rchild = p;
    }
    else{
        r->lchild = p;
    }
} 
void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

struct Node *Search(struct Node* t, int key){
    while(t!=NULL){
        if(key == t->data) return t;
        else if (key < t->data) t = t->lchild;
        else t = t->rchild;
    }
    return NULL;
}
int main()
{
    struct Node *s_temp;
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);

    Inorder(root);
    printf("\n");

    s_temp = Search(root,5);
    if(s_temp){
        printf("key : %d is found\n",s_temp->data);
    }else{
        printf("key not found \n");
    }
    return 0;
}