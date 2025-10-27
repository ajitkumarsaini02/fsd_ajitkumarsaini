#include <iostream>
#define QUEUE_SIZE 50
using namespace std;

struct node {
    int data;
    node* next;
};

node* GetNode() {
    node* p = (node*)malloc(sizeof(node));
    return p;
};


void Initialize(node** front, node** rear) {
    *front = NULL;
    *rear = NULL;
}


bool isEmpty(node** front, node** rear) {
    if (*front == NULL) {
        return true;
    }
    else {
        return false;
    }
}


void EnQueue(node** front, node** rear, int x) {
    node* P = GetNode();
    P->data = x;
    P->next = NULL;

    if (*rear != NULL) {
        (*rear)->next = P;
    }
    else {
        *front = P;
    }
    *rear = P;
}


int DeQueue(node** front, node** rear) {
    if (*front == NULL) {
        cout << "Queue Underflows" << endl;
        exit(1);
    }
    else {
        node* P = *front;
        *front = (*front)->next;
        
        if (*front == NULL) {
            *rear = NULL;
        }
        int x = P->data;
        free(P);
        return x;
    }
}
void Traverse(node** front) {
    if (*front == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }
    node* temp = *front;
    cout << "Queue elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    node* front;
    node* rear;

    Initialize(&front, &rear);

    EnQueue(&front, &rear, 10);
    EnQueue(&front, &rear, 20);
    EnQueue(&front, &rear, 30);

    Traverse(&front);

    cout << "Dequeued element: " << DeQueue(&front, &rear) << endl;
    Traverse(&front);

    EnQueue(&front, &rear, 40);
    Traverse(&front);

    cout << "Dequeued element: " << DeQueue(&front, &rear) << endl;
    Traverse(&front);

    return 0;
}