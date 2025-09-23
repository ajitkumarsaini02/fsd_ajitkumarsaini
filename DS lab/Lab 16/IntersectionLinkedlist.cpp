#include<iostream>
#include<stdlib.h>
#include"LinkedListheader.h"
using namespace std;

Node* IntersectionLinkedList(Node **S1, Node **S2){
    Node *p = *S1;
    Node *q = *S2;
    Node *Start1 = NULL;

    // Merge nodes using InsBeg
    while(p != NULL && q != NULL){
        if(p->info < q->info){
            p = p->Next;
        }
        else if(p->info > q->info){
            q = q->Next;
        }
        else{
            InsBeg(&Start1, q->info);
            q = q->Next;
            p=p->Next;
        }
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
    orderedInsert(&S2,'F');  
    orderedInsert(&S2,'Q');
    orderedInsert(&S2,'P');
    orderedInsert(&S2,'A');
    orderedInsert(&S2,'U');

    cout << "First List: ";
    Traverse(S1);
    cout << "Second List: ";
    Traverse(S2);

    Start1 = IntersectionLinkedList(&S1, &S2);

    cout << "Intersection of List: ";
    Traverse(Start1);

    return 0;
}
