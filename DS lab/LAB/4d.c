// Reverse a Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char info;
    struct Node *Next;
};

struct Node* GetNode() {
    struct Node *p = (struct Node*) malloc(sizeof(struct Node));
    return p;
}

void InsBeg(struct Node **Start, char x) {
    struct Node *p = GetNode();
    p->info = x;
    p->Next = *Start;
    *Start = p;
}

void InsEnd(struct Node **Start, char x) {
    struct Node *p = GetNode();
    p->info = x;
    p->Next = NULL;
    if (*Start == NULL) {
        *Start = p;
    } else {
        struct Node *q = *Start;
        while (q->Next != NULL)
            q = q->Next;
        q->Next = p;
    }
}

void Traverse(struct Node *Start) {
    struct Node *p = Start;
    while (p != NULL) {
        printf("%c ", p->info);
        p = p->Next;
    }
    printf("\n");
}

struct Node* ReverseList(struct Node **Start) {
    struct Node *p = NULL, *c = *Start, *n = NULL;
    while (c != NULL) {
        n = c->Next;   // save next node
        c->Next = p;   // reverse link
        p = c;         // move p ahead
        c = n;         // move c ahead
    }
    *Start = p;        // new start
    return *Start;
}

int main() {
    struct Node *Start = NULL;

    InsBeg(&Start, 'A');
    InsBeg(&Start, 'B');
    InsBeg(&Start, 'C');
    InsEnd(&Start, 'X');
    InsEnd(&Start, 'Y');
    InsEnd(&Start, 'Z');

    printf("Original List: ");
    Traverse(Start);

    ReverseList(&Start);

    printf("Reversed List: ");
    Traverse(Start);

    return 0;
}