// Searching in a Linear Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *Next;
};

// Function to create a new node
struct Node* GetNode() {
    struct Node *p = (struct Node*) malloc(sizeof(struct Node));
    return p;
}

// Insert at beginning
void InsBeg(struct Node **Start, int x) {
    struct Node *p = GetNode();
    p->info = x;
    p->Next = *Start;
    *Start = p;
}

// Insert at end
void InsEnd(struct Node **Start, int x) {
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

// Traverse and display list
void Traverse(struct Node *Start) {
    struct Node *p = Start;
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->Next;
    }
    printf("\n");
}

// Search for an element in the linked list
struct Node* Search(struct Node *Start, int x) {
    struct Node *p = Start;
    while (p != NULL) {
        if (p->info == x)
            return p;  // return the address of found node
        p = p->Next;
    }
    return NULL;  // element not found
}

// Main Function
int main() {
    struct Node *Start = NULL;
    struct Node *loc;

    // Create a linked list
    InsBeg(&Start, 30);
    InsBeg(&Start, 20);
    InsBeg(&Start, 10);
    InsEnd(&Start, 40);
    InsEnd(&Start, 50);

    printf("Linked List: ");
    Traverse(Start);

    int item;
    printf("Enter element to search: ");
    scanf("%d", &item);

    loc = Search(Start, item);

    if (loc != NULL)
        printf("Element %d found at address: %p\n", item, (void*)loc);
    else
        printf("Element %d not found in the list.\n", item);

    return 0;
}