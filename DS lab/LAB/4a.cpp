// Singly Linked List (All Basic Operations)

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    char info;
    Node *Next;
};

Node *Start = NULL;

/* Get new node */
Node* GetNode() {
    Node *p = (Node*) malloc(sizeof(Node));
    return p;
}

/* Insert at Beginning */
void InsBeg(char x) {
    Node *p = GetNode();
    p->info = x;
    p->Next = Start;
    Start = p;
}

/* Insert at End */
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

/* Insert After a Given Node */
void InsAfter(Node *q, char x) {
    if (q == NULL) {
        cout << "Given node is NULL!" << endl;
        return;
    }
    Node *p = GetNode();
    p->info = x;
    p->Next = q->Next;
    q->Next = p;
}

/* Traverse the List */
void Traverse() {
    Node *p = Start;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->Next;
    }
    cout << endl;
}

/* Delete from Beginning */
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

/* Delete After a Given Node */
char DelAfter(Node *q) {
    if (q == NULL || q->Next == NULL) {
        cout << "No node exists after the given node!" << endl;
        exit(1);
    }

    Node *r = q->Next;
    char x = r->info;
    q->Next = r->Next;
    free(r);
    return x;
}

/* Delete from End */
char DelEnd() {
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

/* Main Function */
int main() {
    Start = NULL;

    InsBeg('A');
    InsBeg('B');
    InsBeg('C');
    InsBeg('D');
    InsBeg('E');

    cout << "List after InsBeg: ";
    Traverse();

    InsEnd('X');
    InsEnd('Y');
    InsEnd('Z');
    cout << "List after InsEnd: ";
    Traverse();

    cout << "Deleted element (DelBeg): " << DelBeg() << endl;
    cout << "List after DelBeg: ";
    Traverse();

    cout << "Deleted element (DelEnd): " << DelEnd() << endl;
    cout << "List after DelEnd: ";
    Traverse();

    cout << "Deleted element (DelAfter Start): " << DelAfter(Start) << endl;
    cout << "List after DelAfter: ";
    Traverse();

    return 0;
}
