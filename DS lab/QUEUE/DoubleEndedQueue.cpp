#include <iostream>
#define QUEUE_SIZE 50
using namespace std;

struct node {
    char info;
    struct node *next, *prev;
};

node* GetNode() {
    node* p = (node*)malloc(sizeof(struct node));
    return p;
};

void InsertLeft(node **left, node **right, char x) {
    node *p = GetNode();
    p->info = x;
    p->prev = NULL;
    p->next = *left;
    if (*left != NULL) {
        (*left)->prev = p;
    } else {
        *right = p;
    }
    *left = p;
}

void InsertRight(node **left, node **right, char x) {
    node *p = GetNode();
    p->info = x;
    p->next = NULL;
    p->prev = *right;
    if (*right != NULL) {
        (*right)->next = p;
    } else {
        *left = p;
    }
    *right = p;
}

void DeleteLeft(node **left, node **right){
    if(*left==NULL){
        cout<<"Void Deletion:";
        exit(1);
    }
}

void Traverse(node *left){
    node* temp=left;
    while(temp!=NULL){
        cout<<temp->info<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main() {
    node *left = NULL, *right = NULL;

    InsertLeft(&left, &right, 'A');
    InsertLeft(&left, &right, 'B');
    InsertLeft(&left, &right, 'C');

    cout << "Double Ended Queue: ";
    Traverse(left);
    InsertRight(&left, &right, 'D');
    InsertRight(&left, &right, 'U');
    InsertRight(&left, &right, 'E');
    cout << "Double Ended Queue: ";
    Traverse(left);
    return 0;
}