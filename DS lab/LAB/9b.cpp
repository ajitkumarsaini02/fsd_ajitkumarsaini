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
bool IsLeft(node *P) {
    if (P->father->left == P)
        return true;
    else
        return false;
}
bool IsRight(node *P) {
    if (P->father->right == P)
        return true;
    else
        return false;
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
node *BSTSuccessor(node* P) {
    if (P == NULL) return NULL;
    if (P->right != NULL) {
        return BSTmin(P->right);
    }
    else {
        node* Q = P->father;
        while (Q != NULL && Q->right == P) {
            P = Q;
            Q = Q->father;
        }
        return Q;
    }
}
int BSTDeletion(node *P){
    if (P == NULL) return -1;
    int y = P->data;

    // ***** Case 1 *****
    if (P->left == NULL && P->right == NULL){
        if (IsLeft(P))
            P->father->left = NULL;
        else
            P->father->right = NULL;
    }
    else{
        // ***** Case 2 *****
        if (P->left == NULL || P->right == NULL){
            node *Q;

            if (P->left == NULL)
                Q = P->right;
            else
                Q = P->left;
            node *R = P->father;
            if (IsLeft(P))
                P->father->left = Q;
            else
                P->father->right = Q;
            Q->father = R;
        }

        // ***** Case 3 *****
        else{
            node *A = BSTSuccessor(P);
            int x = BSTDeletion(A);
            P->data = x;
            P = A;
        }
    }

    delete P;
    return y;
}
int main() {
    node *root = NULL;
    root = BSTInsertion(root, 50);
    BSTInsertion(root, 30);
    BSTInsertion(root, 70);
    BSTInsertion(root, 20);
    BSTInsertion(root, 40);
    BSTInsertion(root, 60);
    BSTInsertion(root, 80);
    BSTInsertion(root, 10);
    BSTInsertion(root, 25);
    BSTInsertion(root, 65);
    cout << "Initial tree (Inorder): ";
    InOrder(root);
    cout << "\n";
    cout << "Delete leaf (10): ";
    cout << BSTDeletion(root->left->left->left) << endl;
    cout << "Inorder: ";
    InOrder(root);
    cout << "\n";
    cout << "Delete node with one child (60): ";
    cout << BSTDeletion(root->right->left) << endl;
    cout << "Inorder: ";
    InOrder(root);
    cout << "\n";
    cout << "Delete node with two children (30): ";
    cout << BSTDeletion(root->left) << endl;
    cout << "Inorder: ";
    InOrder(root);
    cout << "\n";
    return 0;
}
