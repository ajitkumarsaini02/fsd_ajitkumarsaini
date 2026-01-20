// Reverse a Linked List

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    char info;
    Node *Next;
};

/* Create a new node */
Node* GetNode() {
    Node *p = (Node*) malloc(sizeof(Node));
    return p;
}

/* Insert at beginning */
void InsBeg(Node **Start, char x) {
    Node *p = GetNode();
    p->info = x;
    p->Next = *Start;
    *Start = p;
}

/* Insert at end */
void InsEnd(Node **Start, char x) {
    Node *p = GetNode();
    p->info = x;
    p->Next = NULL;

    if (*Start == NULL) {
        *Start = p;
    } else {
        Node *q = *Start;
        while (q->Next != NULL)
            q = q->Next;
        q->Next = p;
    }
}

/* Traverse the list */
void Traverse(Node *Start) {
    Node *p = Start;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->Next;
    }
    cout << endl;
}

/* Reverse the linked list */
Node* ReverseList(Node **Start) {
    Node *p = NULL, *c = *Start, *n = NULL;

    while (c != NULL) {
        n = c->Next;   // save next node
        c->Next = p;   // reverse link
        p = c;         // move previous pointer
        c = n;         // move current pointer
    }

    *Start = p;        // update start
    return *Start;
}

/* Main Function */
int main() {
    Node *Start = NULL;

    InsBeg(&Start, 'A');
    InsBeg(&Start, 'B');
    InsBeg(&Start, 'C');
    InsEnd(&Start, 'X');
    InsEnd(&Start, 'Y');
    InsEnd(&Start, 'Z');

    cout << "Original List: ";
    Traverse(Start);

    ReverseList(&Start);

    cout << "Reversed List: ";
    Traverse(Start);

    return 0;
}
