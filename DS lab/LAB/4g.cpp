// Doubly Linked List Implementation

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

/* Create new node */
Node* createNode(int x) {
    Node* p = (Node*) malloc(sizeof(Node));
    p->data = x;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

/* Insert at beginning */
void insertBeg(Node** start, int x) {
    Node* p = createNode(x);
    if (*start == NULL)
        *start = p;
    else {
        p->next = *start;
        (*start)->prev = p;
        *start = p;
    }
}

/* Insert at end */
void insertEnd(Node** start, int x) {
    Node* p = createNode(x);
    if (*start == NULL)
        *start = p;
    else {
        Node* q = *start;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
        p->prev = q;
    }
}

/* Insert after a given node */
void insertAfter(Node* q, int x) {
    if (q == NULL) return;
    Node* p = createNode(x);
    Node* r = q->next;
    p->prev = q;
    p->next = r;
    q->next = p;
    if (r != NULL)
        r->prev = p;
}

/* Insert before a given node */
void insertBefore(Node** start, Node* q, int x) {
    if (q == NULL) return;
    Node* p = createNode(x);
    Node* r = q->prev;
    p->next = q;
    p->prev = r;
    q->prev = p;
    if (r != NULL)
        r->next = p;
    else
        *start = p;
}

/* Delete from beginning */
void delBeg(Node** start) {
    if (*start == NULL) return;
    Node* p = *start;
    *start = (*start)->next;
    if (*start != NULL)
        (*start)->prev = NULL;
    free(p);
}

/* Delete from end */
void delEnd(Node** start) {
    if (*start == NULL) return;
    Node* q = *start;

    if (q->next == NULL) {
        free(q);
        *start = NULL;
        return;
    }

    while (q->next != NULL)
        q = q->next;

    q->prev->next = NULL;
    free(q);
}

/* Delete after a given node */
void delAfter(Node* q) {
    if (q == NULL || q->next == NULL) return;
    Node* p = q->next;
    Node* r = p->next;
    q->next = r;
    if (r != NULL)
        r->prev = q;
    free(p);
}

/* Delete before a given node */
void delBefore(Node** start, Node* q) {
    if (q == NULL || q->prev == NULL) return;
    Node* p = q->prev;
    Node* r = p->prev;
    q->prev = r;
    if (r != NULL)
        r->next = q;
    else
        *start = q;
    free(p);
}

/* Display forward */
void display(Node* start) {
    Node* temp = start;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/* Display reverse */
void displayReverse(Node* start) {
    if (start == NULL) return;
    Node* temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

/* Search a node */
Node* findNode(Node* start, int value) {
    Node* temp = start;
    while (temp != NULL) {
        if (temp->data == value)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

/* Main Function */
int main() {
    Node* start = NULL;

    insertBeg(&start, 10);
    insertBeg(&start, 20);
    insertBeg(&start, 5);
    insertEnd(&start, 30);
    insertEnd(&start, 40);

    Node* node10 = findNode(start, 10);
    insertAfter(node10, 25);

    Node* node30 = findNode(start, 30);
    insertBefore(&start, node30, 15);

    cout << "List after insertions (forward): ";
    display(start);

    cout << "List after insertions (reverse): ";
    displayReverse(start);

    delBeg(&start);
    delEnd(&start);

    Node* node20 = findNode(start, 20);
    delAfter(node20);

    Node* node15 = findNode(start, 15);
    delBefore(&start, node15);

    cout << "List after deletions (forward): ";
    display(start);

    cout << "List after deletions (reverse): ";
    displayReverse(start);

    Node* found = findNode(start, 30);
    if (found)
        cout << "Node with value 30 found." << endl;
    else
        cout << "Node with value 30 not found." << endl;

    found = findNode(start, 100);
    if (found)
        cout << "Node with value 100 found." << endl;
    else
        cout << "Node with value 100 not found." << endl;

    return 0;
}
