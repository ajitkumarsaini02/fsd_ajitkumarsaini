// Searching in a Linear Linked List

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int info;
    Node *Next;
};

/* Create a new node */
Node* GetNode() {
    Node *p = (Node*) malloc(sizeof(Node));
    return p;
}

/* Insert at beginning */
void InsBeg(Node **Start, int x) {
    Node *p = GetNode();
    p->info = x;
    p->Next = *Start;
    *Start = p;
}

/* Insert at end */
void InsEnd(Node **Start, int x) {
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

/* Traverse and display list */
void Traverse(Node *Start) {
    Node *p = Start;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->Next;
    }
    cout << endl;
}

/* Search for an element */
Node* Search(Node *Start, int x) {
    Node *p = Start;
    while (p != NULL) {
        if (p->info == x)
            return p;   // address of found node
        p = p->Next;
    }
    return NULL;        // not found
}

/* Main Function */
int main() {
    Node *Start = NULL;
    Node *loc;

    // Create linked list
    InsBeg(&Start, 30);
    InsBeg(&Start, 20);
    InsBeg(&Start, 10);
    InsEnd(&Start, 40);
    InsEnd(&Start, 50);

    cout << "Linked List: ";
    Traverse(Start);

    int item;
    cout << "Enter element to search: ";
    cin >> item;

    loc = Search(Start, item);

    if (loc != NULL)
        cout << "Element " << item << " found at address: " << loc << endl;
    else
        cout << "Element " << item << " not found in the list." << endl;

    return 0;
}
