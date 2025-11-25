#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct node {
    char data;
    struct node *left;
    struct node *right;
};

node* MakeNode(char x) {
    node *p;
    p = (node*) malloc(sizeof(node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void PreOrder(node *T){
    if ((T) != NULL) {
        cout << (T)->data << ", ";
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

void createNode(node *T){
    int choice;
    cout<<"Wheather the left of "<<T->data<<" Exists?(0/1): ";
    cin>>choice;
    if(choice==1){
        int x;
        cout<<"Enter the left child: "<<T->data<<": ";
        cin>>x;
        node *p=MakeNode(x);
        T->left=p;
        createNode(p);
    }
    cout<<"Wheather the right of "<<T->data<<" Exists?(0/1):  ";
    cin>>choice;
    if(choice==1){
        int x;
        cout<<"Enter the right child "<<T->data<<": ";
        cin>>x;
        node *p=MakeNode(x);
        T->right=p;
        createNode(p);
    }
}

int Height(node *T){
    if(T==NULL){
        return 0;
    }
    else if((T->left==NULL) && (T->right==NULL)){
        return 0;
    }
    else{
        int p=1+max(Height(T->left), Height(T->right));
        return p;
    }
}
int main() {
    node *T;
    int x;
    cout<<"Enter the data of root node: ";
    cin>>x;
    T = MakeNode(x);
    createNode(T);

    cout << "PreOrder Traversal: ";
    PreOrder(T);

    cout << "\nInOrder Traversal: ";
    InOrder(T);

    cout << "\nPostOrder Traversal: ";
    PostOrder(T);
    cout << "\n\nHeight (in nodes): " << Height(T) << "\n";

    return 0;
}
