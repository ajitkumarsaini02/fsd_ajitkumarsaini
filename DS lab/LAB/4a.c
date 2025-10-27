// Singly Linked List (All Basic Operations)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char info;
    struct Node *Next;
};

struct Node *Start = NULL;

struct Node* GetNode() {
    struct Node *p = (struct Node*) malloc(sizeof(struct Node));
    return p;
}

void InsBeg(char x) {
    struct Node *p = GetNode();
    p->info = x;
    p->Next = Start;
    Start = p;
}

void InsEnd(char x) {
    struct Node *p = GetNode();
    p->info = x;
    p->Next = NULL;

    if (Start == NULL) {
        Start = p;
        return;
    }

    struct Node *q = Start;
    while (q->Next != NULL) {
        q = q->Next;
    }
    q->Next = p;
}

void InsAfter(struct Node *q, char x) {
    if (q == NULL) {
        printf("Given node is NULL!\n");
        return;
    }
    struct Node *p = GetNode();
    p->info = x;
    p->Next = q->Next;
    q->Next = p;
}

void Traverse() {
    struct Node *p = Start;
    while (p != NULL) {
        printf("%c ", p->info);
        p = p->Next;
    }
    printf("\n");
}

char DelBeg() {
    if (Start == NULL) {
        printf("List is empty!\n");
        exit(1);
    }

    struct Node *p = Start;
    char x = p->info;
    Start = Start->Next;
    free(p);
    return x;
}

char DelAfter(struct Node *q) {
    if (q == NULL || q->Next == NULL) {
        printf("No node exists after the given node!\n");
        exit(1);
    }

    struct Node *r = q->Next;
    char x = r->info;
    q->Next = r->Next;
    free(r);
    return x;
}

char DelEnd() {
    if (Start == NULL) {
        printf("List is empty!\n");
        exit(1);
    }

    struct Node *p = Start;
    struct Node *c = NULL;

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

    InsBeg('A');
    InsBeg('B');
    InsBeg('C');
    InsBeg('D');
    InsBeg('E');

    printf("List after InsBeg: ");
    Traverse();

    InsEnd('X');
    InsEnd('Y');
    InsEnd('Z');
    printf("List after InsEnd: ");
    Traverse();

    printf("Deleted element (DelBeg): %c\n", DelBeg());
    printf("List after DelBeg: ");
    Traverse();

    printf("Deleted element (DelEnd): %c\n", DelEnd());
    printf("List after DelEnd: ");
    Traverse();

    printf("Deleted element (DelAfter Start): %c\n", DelAfter(Start));
    printf("List after DelAfter: ");
    Traverse();

    return 0;
}