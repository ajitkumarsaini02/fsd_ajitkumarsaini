 //     AJIT KUMAR SAINI     ROLL: 2400320100114
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->prev = p->next = NULL;
    return p;
}

void insertBeg(Node*& start, int x) {
    Node* p = createNode(x);
    if (start == NULL) start = p;
    else {
        p->next = start;
        start->prev = p;
        start = p;
    }
}

void insertEnd(Node*& start, int x) {
    Node* p = createNode(x);
    if (start == NULL) start = p;
    else {
        Node* q = start;
        while (q->next) q = q->next;
        q->next = p;
        p->prev = q;
    }
}

void insertAfter(Node* q, int x) {
    if (q == NULL) return;
    Node* p = createNode(x);
    Node* r = q->next;
    p->prev = q;
    p->next = r;
    q->next = p;
    if (r != NULL) r->prev = p;
}

void insertBefore(Node*& start, Node* q, int x) {
    if (q == NULL) return;
    Node* p = createNode(x);
    Node* r = q->prev;
    p->next = q;
    p->prev = r;
    q->prev = p;
    if (r != NULL) r->next = p;
    else start = p;
}

void delBeg(Node*& start) {
    if (start == NULL) return;
    Node* p = start;
    start = start->next;
    if (start != NULL) start->prev = NULL;
    delete p;
}

void delEnd(Node*& start) {
    if (start == NULL) return;
    Node* q = start;
    if (q->next == NULL) {
        delete q;
        start = NULL;
        return;
    }
    while (q->next) q = q->next;
    q->prev->next = NULL;
    delete q;
}

void delAfter(Node* q) {
    if (q == NULL || q->next == NULL) return;
    Node* p = q->next;
    Node* r = p->next;
    q->next = r;
    if (r != NULL) r->prev = q;
    delete p;
}

void delBefore(Node*& start, Node* q) {
    if (q == NULL || q->prev == NULL) return;
    Node* p = q->prev;
    Node* r = p->prev;
    q->prev = r;
    if (r != NULL) r->next = q;
    else start = q;
    delete p;
}

void display(Node* start) {
    Node* temp = start;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void displayReverse(Node* start) {
    if (!start) return;
    Node* temp = start;
    while (temp->next) temp = temp->next;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

Node* findNode(Node* start, int value) {
    Node* temp = start;
    while (temp) {
        if (temp->data == value) return temp;
        temp = temp->next;
    }
    return NULL;
}

int main() {
    Node* start = NULL;
    insertBeg(start, 10);
    insertBeg(start, 20);
    insertBeg(start, 5);
    insertEnd(start, 30);
    insertEnd(start, 40);
    Node* node10 = findNode(start, 10);
    insertAfter(node10, 25);
    Node* node30 = findNode(start, 30);
    insertBefore(start, node30, 15);
    cout << "List after insertions (forward): ";
    display(start);
    cout << "List after insertions (reverse): ";
    displayReverse(start);
    delBeg(start);
    delEnd(start);
    Node* node20 = findNode(start, 20);
    delAfter(node20);
    Node* node15 = findNode(start, 15);
    delBefore(start, node15);
    cout << "List after deletions (forward): ";
    display(start);
    cout << "List after deletions (reverse): ";
    displayReverse(start);
    Node* found = findNode(start, 30);
    if (found)
        cout << "Node with value 30 found.\n";
    else
        cout << "Node with value 30 not found.\n";
    found = findNode(start, 100);
    if (found)
        cout << "Node with value 100 found.\n";
    else
        cout << "Node with value 100 not found.\n";
    
}