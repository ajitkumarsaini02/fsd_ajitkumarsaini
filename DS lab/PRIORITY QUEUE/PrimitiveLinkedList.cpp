#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
    int info;
    Node *Next;
};
Node* GetNode() {
    Node *p = (Node*) malloc(sizeof(Node));
    return p;
}

void InsBeg(Node **Start,int x) {
    Node *p = GetNode();
    p->info = x;
    p->Next = *Start;
    *Start = p;
}
void InsAfter(Node **q, int x){
    Node *p = GetNode();
    p->info = x;
    Node *r= (*q)->Next;
    (*q)->Next = p;
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
int DelBeg(Node **Start){
    Node *p=*Start;
    *Start=(*Start)->Next;
    char x=p->info;
    free(p);
    return x;
}
void EnQueue(Node **PQ, int x){
    Node * q=NULL;
    Node *p=*PQ;
    while(p!=NULL && x>=p->info){
        q=p;
        p=p->Next;
    }
    if(q==NULL) InsBeg(&(*PQ),x);
    else InsAfter(&q,x);
}
int DeQueue(Node **PQ){
    int x=DelBeg(PQ);
}
int main() {
    Node* PQ = NULL;
    InsBeg(&PQ, 6);
    InsBeg(&PQ, 5);
    InsBeg(&PQ, 3);

    Traverse(PQ);

    EnQueue(&PQ, 7);
    EnQueue(&PQ, 4);
    EnQueue(&PQ, 1);

    Traverse(PQ);

    DeQueue(&PQ);

    Traverse(PQ);
    return 0;
}