#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node {
    char info;
    struct Node *Next;
};

struct Node *Start;   // global pointer

// New Node allocate karna
Node *GetNode() {
    Node *p;
    p = (Node*)malloc(sizeof(struct Node));
    return p;
}

// Insert at Beginning
void InsBeg(char x) {
    Node *p = GetNode();
    p->info = x;
    p->Next = Start;
    Start = p;
}

// Traverse Linked List
void Traverse() {
    Node *p = Start;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->Next;
    }
    cout << endl;
}

int main() {
    Start = NULL;   // initially list empty

    InsBeg('A');
    InsBeg('B');
    InsBeg('C');

    cout << "Linked List: ";
    Traverse();

    return 0;
}
