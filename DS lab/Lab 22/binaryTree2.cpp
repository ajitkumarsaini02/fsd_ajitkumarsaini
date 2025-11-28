#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

node* MakeNode(int x) {
    node *p = new node;
    p->data = x;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void PreOrder(node *T){
    if (T != nullptr) {
        cout << T->data << ", ";
        PreOrder(T->left);
        PreOrder(T->right);
    }
}

void InOrder(node *T){
    if (T != nullptr) {
        InOrder(T->left);
        cout << T->data << ", ";
        InOrder(T->right);
    }
}

void PostOrder(node *T){
    if (T != nullptr) {
        PostOrder(T->left);
        PostOrder(T->right);
        cout << T->data << ", ";
    }
}

void createNode(node *T){
    int choice;
    cout << "Whether the left of " << T->data << " exists? (0/1): ";
    cin >> choice;
    if (choice == 1) {
        int x;
        cout << "Enter the left child of " << T->data << ": ";
        cin >> x;
        node *p = MakeNode(x);
        T->left = p;
        createNode(p);
    }

    cout << "Whether the right of " << T->data << " exists? (0/1): ";
    cin >> choice;
    if (choice == 1) {
        int x;
        cout << "Enter the right child of " << T->data << ": ";
        cin >> x;
        node *p = MakeNode(x);
        T->right = p;
        createNode(p);
    }
}

int main() {
    node *T;
    int x;
    cout << "Enter the data of root node: ";
    cin >> x;
    T = MakeNode(x);
    createNode(T);

    cout << "PreOrder Traversal: ";
    PreOrder(T);

    cout << "\nInOrder Traversal: ";
    InOrder(T);

    cout << "\nPostOrder Traversal: ";
    PostOrder(T);

    cout << endl;
    return 0;
}
