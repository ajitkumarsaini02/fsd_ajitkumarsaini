// Linked List with Count Function

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

int CountNode(struct Node *Start) {
    int count = 0;
    struct Node *p = Start;
    while (p != NULL) {
        count++;
        p = p->Next;
    }
    return count;
}

int main() {
    struct Node *Start = NULL;

    InsBeg(&Start, 'A');
    InsBeg(&Start, 'B');
    InsBeg(&Start, 'C');

    InsEnd(&Start, 'X');
    InsEnd(&Start, 'Y');
    InsEnd(&Start, 'Z');

    printf("Linked List: ");
    Traverse(Start);

    printf("Number of nodes: %d\n", CountNode(Start));

    return 0;
}