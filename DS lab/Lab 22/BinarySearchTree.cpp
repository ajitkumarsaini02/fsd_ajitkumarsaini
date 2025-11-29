#include<iostream>
using namespace std;
struct node {
    int data;
    struct node *left;
    struct node *right;
};

node* MakeNode(int x) {
    node *p = new node;
    p->data = x;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void InOrder(node *T){
    if (T != nullptr) {
        InOrder(T->left);
        cout << T->data << ", ";
        InOrder(T->right);
    }
}

node *BSTInsertion(node *T,int x){
    node *p=T,*q=NULL;
    while(p!=NULL){
        q=p;
        if(x<p->data) p=p->left;
        else p=p->right; 
    }
    if(T==NULL){
        T=MakeNode(x);
    }
    else if(x<q->data) q->left=MakeNode(x);
    else q->right=MakeNode(x);
}

node *BSTmin(node *t){
    while(t->left!=NULL){
        t=t->left;
    }
    return t;
}

node *BSTmax(node *t){
    while(t->right!=NULL){
        t=t->right;
    }
    return t;
}

int main(){
    node *root=NULL;
    root =BSTInsertion(root,100);
    BSTInsertion(root,10);
    BSTInsertion(root,150);
    BSTInsertion(root,200);
    BSTInsertion(root,130);
    cout<<"Inorder Traversal:";
    InOrder(root);
    cout<<endl;
    node *p=BSTmin(root);
    cout<<"Minimum of the root: "<<p->data<<endl;
    p=BSTmax(root);
    cout<<"Maxmum of the root: "<<p->data<<endl;
}