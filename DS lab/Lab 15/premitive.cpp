#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    char info;
    Node *Next;
};

Node *Start = NULL;

Node* GetNode() {
    Node *p = (Node*) malloc(sizeof(Node));
    return p;
}

void InsBeg(char x) {
    Node *p = GetNode();
    p->info = x;
    p->Next = Start;
    Start = p;
}

void InsEnd(char x) {
    Node *p = GetNode();
    p->info = x;
    p->Next = NULL;
    if (Start == NULL) {
        Start = p;
        return;
    }
    Node *q = Start;
    while (q->Next != NULL) {
       q = q->Next;
    }
    q->Next = p;
}

// Insert after node q
void InsAfter(Node *q, char x){
    Node *p = GetNode();
    p->info = x;
    Node *r= q->Next;
    q->Next = p;
}

void Traverse() {
    Node *p = Start;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->Next;
    }
    cout << endl;
}

// Delete first node
char DelBeg() {
    if (Start == NULL) {
        cout << "List is empty!" << endl;
        exit(1);
    }
    Node *p = Start;
    char x = p->info;
    Start = Start->Next;
    free(p);
    return x;
}

// Delete node after q
char DelAfter(Node *q){ 
    if (q == NULL || q->Next == NULL) {
        cout << "No node exists after given node!" << endl;
        exit(1);
    }
    Node *r = q->Next;
    char x = r->info;
    q->Next = r->Next;
    free(r);
    return x;
}

// Delete last node
char DelEnd(){
    if (Start == NULL) {
        cout << "List is empty!" << endl;
        exit(1);
    }
    Node *p = Start;
    Node *c = NULL;
    while (p->Next != NULL) {
        c = p;
        p = p->Next;
    }
    char x = p->info;
    if (c != NULL)
        c->Next = NULL;  
    else
        Start = NULL;      
    free(p);
    return x;
}

int main() {
    Start = NULL;

    // Insert nodes at beginning
    InsBeg('A');
    InsBeg('B');
    InsBeg('C');
    InsBeg('D');
    InsBeg('E'); 
    cout << "List after InsBeg: ";
    Traverse();

    // Insert nodes at end
    InsEnd('X');
    InsEnd('Y');
    InsEnd('Z'); 
    cout << "List after InsEnd: ";
    Traverse();

    // Delete first node
    cout << "Deleted element (DelBeg): " << DelBeg() << endl;
    cout << "List after DelBeg: ";
    Traverse();

    // Delete last node
    cout << "Deleted element (DelEnd): " << DelEnd() << endl;
    cout << "List after DelEnd: ";
    Traverse();

    // Delete node after first node
    cout << "Deleted element (DelAfter Start): " << DelAfter(Start) << endl;
    cout << "List after DelAfter: ";
    Traverse();

    return 0;
}
