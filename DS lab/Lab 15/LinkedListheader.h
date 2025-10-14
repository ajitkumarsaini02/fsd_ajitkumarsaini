#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
    char info;
    Node *Next;
};
Node* GetNode() {
    Node *p = (Node*) malloc(sizeof(Node));
    return p;
}

void InsBeg(Node **Start,char x) {
    Node *p = GetNode();
    p->info = x;
    p->Next = *Start;
    *Start = p;
}

void InsEnd(Node **Start,char x) {
    Node *p = GetNode();
    p->info = x;
    p->Next = NULL;
    if (*Start == NULL) {
        *Start = p;
        return ;
    }
    Node *q = *Start;
    while (q->Next != NULL) {
       q = q->Next;
    }
    q->Next = p;
}

void InsAfter(Node **Start,Node *q, char x){
    Node *p = GetNode();
    p->info = x;
    Node *r= q->Next;
    q->Next = p;
    p->Next = r;    
}

void Traverse(Node *Start) {
    Node *p = Start;
    while (p != NULL) {
        cout << p->info<<" " ;
        p = p->Next;
    }
    cout<<endl;
    
}
char DelBeg(Node **Start){
    Node *p=*Start;
    *Start=(*Start)->Next;
    char x=p->info;
    free(p);
    return x;
}
char DelAfter(Node **Start,Node *q){
    Node *p=q->Next;
    Node *r=p->Next;
    q->Next=r;
    char x=p->info;
    free(p);
    return x;
}
 char DelEnd(Node **Start){
    Node *p=*Start;
    Node *c=NULL;
    while(p->Next!=NULL){
        c=p;
        p=p->Next;
    }
    char x=p->info;
    free(p);
    c->Next=NULL;
    return x;
 }
 void orderedInsert(Node **Start, char x){
    Node *p,*q;
    p=*Start;
    q=NULL;
    while(p!=NULL && x>p->info){
        q=p;
        p=p->Next;
    }    
    if(q==NULL){
        InsBeg(Start,x);
     }
    else{
        InsAfter(Start,q,x);
     }
           
 }
int CountNode(Node *Start) {
    int count = 0;
    Node *p = Start;
    while (p != NULL) {
        count++;
        p = p->Next;
    }
    return count;
}

Node *MiddleNodeList(Node **Start){
    Node *t=(*Start);
    Node *r=(*Start)->Next;
    while(r!=NULL && r->Next!=NULL){
        t=t->Next;
        r=r->Next->Next;
    }
    return t;
}

Node *MiddleNode(Node **Start){
    int c=CountNode(*Start);
    int i=1;
    Node *p=*Start;
    for(i=1;i<(c/2);i++){
        p=p->Next;
    }
    return p;
}

Node *ReverseList(Node **Start){
    Node *p,*c,*n;
    p=NULL;
    n=c->Next;
    while(c!=NULL){
        c->Next=p;
        p=c;
        c=n;
        if(n!=NULL){
            n=n->Next;
        }

    }
    *Start = p;
    return *Start;       
}
