#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root = NULL;
int NodeHeight(struct Node *p){
    int hl, hr;
    if(p){
        hl = p->lchild?p->lchild->height:0;
        hr = p->rchild?p->rchild->height:0;
    }
    return hl>hr ? hl +1 : hr +1;
}

int BalanceFactor(struct Node *p){
    int hl, hr;
    if(p){
        hl = p->lchild?p->lchild->height:0;
        hr = p->rchild?p->rchild->height:0;
    }
    return hl-hr;
}
struct Node* Rinsert(struct Node *p, int key){
    struct Node *t =NULL;
    if(p==NULL){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->rchild = t->lchild = NULL;
        return t;
    }
    if(key<p->data){
        p->lchild=  Rinsert(p->lchild,key);
    }
    else{
        p->rchild=  Rinsert(p->rchild,key);
    }
    p->height = NodeHeight(p);

    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        return RLRotation(p);
    return p;
}
int main()
{
    return 0;
}