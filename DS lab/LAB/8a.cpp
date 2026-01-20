#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
    char data;
    struct node *left;
    struct node *right;
};

node* MakeNode(char T) {
    node *p;
    p = (node*) malloc(sizeof(node));
    p->data = T;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void PreOrder(node *T){
    if (T != NULL) {
        cout << T->data << ", ";
        PreOrder(T->left);
        PreOrder(T->right);
    }
}

void InOrder(node *T){
    if (T != NULL) {
        InOrder(T->left);
        cout << T->data << ", ";
        InOrder(T->right);
    }
}

void PostOrder(node *T){
    if (T != NULL) {
        PostOrder(T->left);
        PostOrder(T->right);
        cout << T->data << ", ";
    }
}

int main() {
    node *T;
    T = MakeNode('A');
    T->left = MakeNode('B');
    T->right = MakeNode('C');
    T->left->left = MakeNode('D');
    cout << "PreOrder Traversal: ";
    PreOrder(T);
    cout << "\nInOrder Traversal: ";
    InOrder(T);
    cout << "\nPostOrder Traversal: ";
    PostOrder(T);

    return 0;
}
