#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

node* MakeNode(int x) {
    node *p;
    p = (node*) malloc(sizeof(node));
    p->data = x;
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

void createNode(node **T){
    int choice;
    cout<<"Wheather the left of "<<(*T)->data<<" Exists?(0/1): ";
    cin>>choice;
    if(choice==1){
        int x;
        cout<<"Enter the left child: "<<(*T)->data<<": ";
        cin>>x;
        node *p=MakeNode(x);
        (*T)->left=p;
        createNode(&p);
    }
    cout<<"Wheather the right of "<<(*T)->data<<" Exists?(0/1):  ";
    cin>>choice;
    if(choice==1){
        int x;
        cout<<"Enter the right child "<<(*T)->data<<": ";
        cin>>x;
        node *p=MakeNode(x);
        (*T)->right=p;
        createNode(&p);
    }
}
int main() {
    node *T;
    int x;
    cout<<"Enter the data of root node: ";
    cin>>x;
    T = MakeNode(x);
    createNode(&T);

    cout << "PreOrder Traversal: ";
    PreOrder(T);

    cout << "\nInOrder Traversal: ";
    InOrder(T);

    cout << "\nPostOrder Traversal: ";
    PostOrder(T);

    return 0;
}
