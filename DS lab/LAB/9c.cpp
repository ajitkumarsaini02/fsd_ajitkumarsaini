#include<iostream>
using namespace std;
struct node {
    int data;
    struct node *left;
    struct node *right;
    struct node *father;
};

node* MakeNode(int x) {
    node *p = new node;
    p->data = x;
    p->left = nullptr;
    p->right = nullptr;
    p->father=nullptr;
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
    node *r=MakeNode(x);
    if(T==NULL){
        T=r;
    }
    else if(x<q->data){
        q->left=r;
        r->father=q;
    } 
    else{
        q->right=r;
        r->father=q;
    } 
    return T;
}

node *BSTmin(node *T){
    if (T == NULL) return NULL;
    while(T->left!=NULL){
        T=T->left;
    }
    return T;
}

node *BSTmax(node *T){
    if (T == NULL) return NULL;
    while(T->right!=NULL){
        T=T->right;
    }
    return T;
}
int main() {
    node *root = nullptr;

    root = BSTInsertion(root, 50);
    root = BSTInsertion(root, 30);
    root = BSTInsertion(root, 70);
    root = BSTInsertion(root, 20);
    root = BSTInsertion(root, 40);
    root = BSTInsertion(root, 60);
    root = BSTInsertion(root, 80);
    root = BSTInsertion(root, 10);
    root = BSTInsertion(root, 25);
    root = BSTInsertion(root, 65);

    cout << "Inorder Traversal: ";
    InOrder(root);
    cout << "\n";

    node *mn = BSTmin(root);
    if (mn) cout << "Minimum: " << mn->data << "\n";

    node *mx = BSTmax(root);
    if (mx) cout << "Maximum: " << mx->data << "\n";

    return 0;
}
