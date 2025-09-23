#include<iostream>
#include<stdlib.h>
#include"LinkedListheader.h"
using namespace std;
Node *ConcatenateLinkedList(Node **S1, Node **S2){
    Node *p;
    if(S1==NULL){
        return *S2;
    }
    if(*S2==NULL){
        return *S1;
    }
    p=*S1;
    while(p->Next!=NULL){
        p=p->Next;
    }
    p->Next=*S2;
    return *S1;
}
int main(){
    Node *Start1 = NULL, *S1 = NULL, *S2 = NULL;

    orderedInsert(&S1,'D');
    orderedInsert(&S1,'B');  
    orderedInsert(&S1,'A');
    orderedInsert(&S1,'C');
    orderedInsert(&S1,'F');
    orderedInsert(&S1,'E');

    orderedInsert(&S2,'S');
    orderedInsert(&S2,'F');  
    orderedInsert(&S2,'Q');
    orderedInsert(&S2,'P');
    orderedInsert(&S2,'A');
    orderedInsert(&S2,'U');

    cout << "First List: ";
    Traverse(S1);
    cout << "Second List: ";
    Traverse(S2);
    Start1=ConcatenateLinkedList(&S1, &S2);
    cout << "Concatenated List: ";
    Traverse(Start1);

    return 0;
}