// Circular Linked List (Insertion and Deletion)

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int info;
    Node *next;
};

/* Create a new node */
Node* GetNode(int x) {
    Node* p = (Node*) malloc(sizeof(Node));
    if (p == NULL) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }
    p->info = x;
    p->next = NULL;
    return p;
}

/* Insert at Beginning */
void InsBeg(Node **CSTART, int x) {
    Node* p = GetNode(x);
    if (*CSTART == NULL) {
        p->next = p;
        *CSTART = p;
    } else {
        p->next = (*CSTART)->next;
        (*CSTART)->next = p;
    }
}

/* Insert After a Given Node */
void InsAft(Node* Q, int x) {
    if (Q == NULL) return;
    Node* p = GetNode(x);
    p->next = Q->next;
    Q->next = p;
}

/* Insert at End */
void InsEnd(Node **CSTART, int x) {
    Node* p = GetNode(x);
    if (*CSTART == NULL) {
        p->next = p;
        *CSTART = p;
    } else {
        p->next = (*CSTART)->next;
        (*CSTART)->next = p;
        *CSTART = p;
    }
}

/* Delete from Beginning */
void DelBeg(Node **CSTART) {
    if (*CSTART == NULL) return;

    Node* p = (*CSTART)->next;
    if (p == *CSTART) {   // only one node
        free(p);
        *CSTART = NULL;
    } else {
        (*CSTART)->next = p->next;
        free(p);
    }
}

/* Delete from End */
void DelEnd(Node **CSTART) {
    if (*CSTART == NULL) return;

    Node* q = (*CSTART)->next;
    if (q == *CSTART) {   // only one node
        free(*CSTART);
        *CSTART = NULL;
        return;
    }

    while (q->next != *CSTART)
        q = q->next;

    Node* p = *CSTART;
    q->next = (*CSTART)->next;
    *CSTART = q;
    free(p);
}

/* Delete After a Given Node */
void DelAft(Node **CSTART, Node *Q) {
    if (*CSTART == NULL || Q == NULL || Q->next == NULL)
        return;

    Node* p = Q->next;
    Q->next = p->next;

    if (p == *CSTART)
        *CSTART = Q;

    free(p);
}

/* Traverse Circular Linked List */
void Traverse(Node* CSTART) {
    if (CSTART == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* p = CSTART->next;
    do {
        cout << p->info << " ";
        p = p->next;
    } while (p != CSTART->next);
    cout << endl;
}

/* Main Function */
int main() {
    Node* CSTART = NULL;

    InsBeg(&CSTART, 10);
    InsBeg(&CSTART, 20);
    InsBeg(&CSTART, 30);
    InsBeg(&CSTART, 40);
    InsEnd(&CSTART, 50);
    InsEnd(&CSTART, 60);
    InsAft(CSTART->next, 25);

    cout << "Initial List: ";
    Traverse(CSTART);

    DelBeg(&CSTART);
    cout << "After DelBeg: ";
    Traverse(CSTART);

    DelEnd(&CSTART);
    cout << "After DelEnd: ";
    Traverse(CSTART);

    DelAft(&CSTART, CSTART->next);
    cout << "After DelAft: ";
    Traverse(CSTART);

    InsEnd(&CSTART, 70);
    InsEnd(&CSTART, 80);
    InsBeg(&CSTART, 5);

    cout << "After more insertions: ";
    Traverse(CSTART);

    return 0;
}
