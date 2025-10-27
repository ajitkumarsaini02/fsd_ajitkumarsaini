// Doubly Linked List Implementation
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int x) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = x;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

void insertBeg(struct Node** start, int x) {
    struct Node* p = createNode(x);
    if (*start == NULL)
        *start = p;
    else {
        p->next = *start;
        (*start)->prev = p;
        *start = p;
    }
}

void insertEnd(struct Node** start, int x) {
    struct Node* p = createNode(x);
    if (*start == NULL)
        *start = p;
    else {
        struct Node* q = *start;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
        p->prev = q;
    }
}

void insertAfter(struct Node* q, int x) {
    if (q == NULL) return;
    struct Node* p = createNode(x);
    struct Node* r = q->next;
    p->prev = q;
    p->next = r;
    q->next = p;
    if (r != NULL)
        r->prev = p;
}

void insertBefore(struct Node** start, struct Node* q, int x) {
    if (q == NULL) return;
    struct Node* p = createNode(x);
    struct Node* r = q->prev;
    p->next = q;
    p->prev = r;
    q->prev = p;
    if (r != NULL)
        r->next = p;
    else
        *start = p;
}

void delBeg(struct Node** start) {
    if (*start == NULL) return;
    struct Node* p = *start;
    *start = (*start)->next;
    if (*start != NULL)
        (*start)->prev = NULL;
    free(p);
}

void delEnd(struct Node** start) {
    if (*start == NULL) return;
    struct Node* q = *start;
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

void delAfter(struct Node* q) {
    if (q == NULL || q->next == NULL) return;
    struct Node* p = q->next;
    struct Node* r = p->next;
    q->next = r;
    if (r != NULL)
        r->prev = q;
    free(p);
}

void delBefore(struct Node** start, struct Node* q) {
    if (q == NULL || q->prev == NULL) return;
    struct Node* p = q->prev;
    struct Node* r = p->prev;
    q->prev = r;
    if (r != NULL)
        r->next = q;
    else
        *start = q;
    free(p);
}

void display(struct Node* start) {
    struct Node* temp = start;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayReverse(struct Node* start) {
    if (start == NULL) return;
    struct Node* temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

struct Node* findNode(struct Node* start, int value) {
    struct Node* temp = start;
    while (temp != NULL) {
        if (temp->data == value)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int main() {
    struct Node* start = NULL;

    insertBeg(&start, 10);
    insertBeg(&start, 20);
    insertBeg(&start, 5);
    insertEnd(&start, 30);
    insertEnd(&start, 40);

    struct Node* node10 = findNode(start, 10);
    insertAfter(node10, 25);

    struct Node* node30 = findNode(start, 30);
    insertBefore(&start, node30, 15);

    printf("List after insertions (forward): ");
    display(start);

    printf("List after insertions (reverse): ");
    displayReverse(start);

    delBeg(&start);
    delEnd(&start);

    struct Node* node20 = findNode(start, 20);
    delAfter(node20);

    struct Node* node15 = findNode(start, 15);
    delBefore(&start, node15);

    printf("List after deletions (forward): ");
    display(start);

    printf("List after deletions (reverse): ");
    displayReverse(start);

    struct Node* found = findNode(start, 30);
    if (found)
        printf("Node with value 30 found.\n");
    else
        printf("Node with value 30 not found.\n");

    found = findNode(start, 100);
    if (found)
        printf("Node with value 100 found.\n");
    else
        printf("Node with value 100 not found.\n");

    return 0;
}