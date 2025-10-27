// Circular Linked List (Insertion and Deletion)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

// Function to create a new node
struct Node* GetNode(int x) {
    struct Node* p = (struct Node*) malloc(sizeof(struct Node));
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    p->info = x;
    p->next = NULL;
    return p;
}

// Insert at Beginning
void InsBeg(struct Node **CSTART, int x) {
    struct Node* p = GetNode(x);
    if (*CSTART == NULL) {
        p->next = p;
        *CSTART = p;
    } else {
        p->next = (*CSTART)->next;
        (*CSTART)->next = p;
    }
}

// Insert After a Given Node
void InsAft(struct Node* Q, int x) {
    if (Q == NULL) return;
    struct Node* p = GetNode(x);
    p->next = Q->next;
    Q->next = p;
}

// Insert at End
void InsEnd(struct Node **CSTART, int x) {
    struct Node* p = GetNode(x);
    if (*CSTART == NULL) {
        p->next = p;
        *CSTART = p;
    } else {
        p->next = (*CSTART)->next;
        (*CSTART)->next = p;
        *CSTART = p;
    }
}

// Delete from Beginning
void DelBeg(struct Node **CSTART) {
    if (*CSTART == NULL) return;
    struct Node* p = (*CSTART)->next;
    if (p == *CSTART) { // Only one node
        free(p);
        *CSTART = NULL;
    } else {
        (*CSTART)->next = p->next;
        free(p);
    }
}

// Delete from End
void DelEnd(struct Node **CSTART) {
    if (*CSTART == NULL) return;
    struct Node* q = (*CSTART)->next;
    if (q == *CSTART) { // Only one node
        free(*CSTART);
        *CSTART = NULL;
        return;
    }
    while (q->next != *CSTART)
        q = q->next;
    struct Node* p = *CSTART;
    q->next = (*CSTART)->next;
    *CSTART = q;
    free(p);
}

// Delete After a Given Node
void DelAft(struct Node **CSTART, struct Node *Q) {
    if (*CSTART == NULL || Q == NULL || Q->next == NULL) return;
    struct Node* p = Q->next;
    Q->next = p->next;
    if (p == *CSTART)
        *CSTART = Q;
    free(p);
}

// Traverse the Circular Linked List
void Traverse(struct Node* CSTART) {
    if (CSTART == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* p = CSTART->next;
    do {
        printf("%d ", p->info);
        p = p->next;
    } while (p != CSTART->next);
    printf("\n");
}

// Main Function
int main() {
    struct Node* CSTART = NULL;

    InsBeg(&CSTART, 10);
    InsBeg(&CSTART, 20);
    InsBeg(&CSTART, 30);
    InsBeg(&CSTART, 40);
    InsEnd(&CSTART, 50);
    InsEnd(&CSTART, 60);
    InsAft(CSTART->next, 25);

    printf("Initial List: ");
    Traverse(CSTART);

    DelBeg(&CSTART);
    printf("After DelBeg: ");
    Traverse(CSTART);

    DelEnd(&CSTART);
    printf("After DelEnd: ");
    Traverse(CSTART);

    DelAft(&CSTART, CSTART->next);
    printf("After DelAft: ");
    Traverse(CSTART);

    InsEnd(&CSTART, 70);
    InsEnd(&CSTART, 80);
    InsBeg(&CSTART, 5);

    printf("After more insertions: ");
    Traverse(CSTART);

    return 0;
}
