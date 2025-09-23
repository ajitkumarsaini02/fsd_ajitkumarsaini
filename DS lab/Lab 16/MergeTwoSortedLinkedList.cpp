#include<iostream>
#include<stdlib.h>
#include"LinkedListheader.h"
using namespace std;

Node* MergeLinkedList(Node **S1, Node **S2){
    Node *p = *S1;
    Node *q = *S2;
    Node *Start1 = NULL;

    // Merge nodes using InsBeg
    while(p != NULL && q != NULL){
        if(p->info < q->info){
            InsBeg(&Start1, p->info);
            p = p->Next;
        }
        else{
            InsBeg(&Start1, q->info);
            q = q->Next;
        }
    }

    // Insert remaining nodes
    while(p != NULL){
        InsBeg(&Start1, p->info);
        p = p->Next;
    }
    while(q != NULL){
        InsBeg(&Start1, q->info);
        q = q->Next;
    }

    // Reverse the list to get correct order
    ReverseList(&Start1);

    return Start1;
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
    orderedInsert(&S2,'K');  
    orderedInsert(&S2,'Q');
    orderedInsert(&S2,'P');
    orderedInsert(&S2,'M');
    orderedInsert(&S2,'U');

    cout << "First List: ";
    Traverse(S1);
    cout << "Second List: ";
    Traverse(S2);

    Start1 = MergeLinkedList(&S1, &S2);

    cout << "Merged List: ";
    Traverse(Start1);

    return 0;
}
