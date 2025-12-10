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
int main(){
    node *root = NULL;
    int n, x;
    cout << "How many values to insert? ";
    cin >> n;
    cout << "Enter values:\n";
    for(int i = 0; i < n; i++){
        cin >> x;
        root = BSTInsertion(root, x);
    }
    cout << "Inorder Traversal (Sorted): ";
    InOrder(root);

    return 0;
}