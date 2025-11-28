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
int CountNodes(node *T){
    if(T==NULL){
        return 0;
    }
    else{
        int p=1+CountNodes(T->left)+CountNodes(T->right);
        return p;
    }
}

int CountLeafs(node *T){
    if(T==NULL){
        return 0;
    }
    else if((T->left==NULL) && (T->right==NULL)){
        return 1;
    }
    else{
        int p=CountLeafs(T->left)+CountLeafs(T->right);
        return p;
    }
}

int CountN1(node *T){
    if(T==NULL){
        return 0;
    }
    else if((T->left==NULL) && (T->right==NULL)){
        return 0;
    }
    else if((T->left!=NULL) && (T->right!=NULL)){
        int a=CountN1(T->left)+CountN1(T->right);
        return a;
    }
    else{
        int p=1+CountN1(T->left)+CountN1(T->right);
        return p;
    }
}

int CountN2(node *T){
    if(T==NULL){
        return 0;
    }
    else if((T->left==NULL) && (T->right==NULL)){
        return 0;
    }
    else if((T->left!=NULL) && (T->right!=NULL)){
        int a=1+CountN2(T->left)+CountN2(T->right);
        return a;
    }
    else{
        int p=CountN2(T->left)+CountN2(T->right);
        return p;
    }
}

bool isStrict(node* root) {
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if (root->left != NULL && root->right != NULL)
        return isStrict(root->left) && isStrict(root->right);
    return false;
}

int completeFlag = 0;

bool isComplete(node* root) {
    if (root == NULL)
        return true;

    if (completeFlag == 1) {
        if (root->left != NULL || root->right != NULL)
            return false;
    }

    if (root->left == NULL && root->right != NULL)
        return false;

    if (root->left == NULL || root->right == NULL)
        completeFlag = 1;

    return isComplete(root->left) && isComplete(root->right);
}


int main() {
    node* T;
    char x;

    cout << "Enter data for root node: ";
    cin >> x;

    T = MakeNode(x);
    createNode(T);

    cout << "\nPreorder: ";
    PreOrder(T);

    cout << "\nInorder: ";
    InOrder(T);

    cout << "\nPostorder: ";
    PostOrder(T);

    cout << "\n\nTotal Nodes: " << CountNodes(T);
    cout << "\nLeaf Nodes: " << CountLeafs(T);
    cout << "\nNodes with 1 Child: " << CountN1(T);
    cout << "\nNodes with 2 Children: " << CountN2(T);

    cout << "\n\nStrict Binary Tree: ";
    cout << (isStrict(T) ? "YES" : "NO");

    cout << "\nComplete Binary Tree: ";
    cout << (isComplete(T) ? "YES" : "NO");

    cout << endl;
    return 0;
}
