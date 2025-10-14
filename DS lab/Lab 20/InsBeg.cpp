#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node {
    char info;
    Node *Next;
};
Node *CStart = NULL;
Node* GetNode() {
    Node *p = (Node*) malloc(sizeof(Node));
    return p;
}

void Traverse() {
    Node *p = CStart->Next;
    while (p != CStart) {
        cout << p->info << " ";
        p = p->Next;
    }
    cout<<p->info<<" ";
}

void InsBeg(char x){
    Node *p = GetNode();
    p->info = x;
    if(CStart!=NULL){
      p->Next = CStart->Next;
      CStart->Next = p;
    }
    else{
        p->Next=p;
        CStart=p;
    }
}

 void InsAfter(Node *q, char x){
    if(q==NULL){
        cout<<"Void interstion:";
        exit(1);
    }
    else{
        Node *r;
        Node *p=GetNode();
        p->info=x;
        r=q->Next;
        p->Next=r;
    }
 }

 void InsEnd(char x){
    Node *p=GetNode();
    p->info=x;
     if(CStart!=NULL){
       p->Next = CStart->Next;
       CStart->Next = p; 
       CStart=p;
    }
    else{
        p->Next=p;
        CStart=p;
    }
    cout<<p->info<<" ";
 }

int main(){
    InsBeg('A');
    InsBeg('F');
    InsBeg('B');
    Traverse();
    InsAfter(CStart,'H');
    InsEnd('S');

}