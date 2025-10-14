 //     AJIT KUMAR SAINI      ROLL NO: 2400320100114
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
    int coeff;
    int pow;
    Node *next;
};
Node* GetNode(int coeff, int pow) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}
void InsertEnd(Node* &poly, int coeff, int pow) {
    Node* newNode = GetNode(coeff, pow);
    if (poly == NULL) {
        poly = newNode;
        return;
    }
    Node* temp = poly;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void Traverse(Node* poly) {
    while (poly != NULL) {
        cout << poly->coeff << "x^" << poly->pow;
        poly = poly->next;
        if (poly != NULL)
            cout << " + ";
    }
    cout << endl;
}
Node* AddPolynomial(Node* poly1, Node* poly2) {
    Node* poly3 = NULL;
    Node* p = poly1;
    Node* q = poly2;
    while (p != NULL && q != NULL) {
        if (p->pow == q->pow) {
            InsertEnd(poly3, p->coeff + q->coeff, p->pow);
            p = p->next;
            q = q->next;
        }
        else if (p->pow > q->pow) {
            InsertEnd(poly3, p->coeff, p->pow);
            p = p->next;
        }
        else {
            InsertEnd(poly3, q->coeff, q->pow);
            q = q->next;
        }
    }
    while (p != NULL) {
        InsertEnd(poly3, p->coeff, p->pow);
        p = p->next;
    }
    while (q != NULL) {
        InsertEnd(poly3, q->coeff, q->pow);
        q = q->next;
    }
    return poly3;
}
int main() {
    // First Example
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* poly3 = NULL;

    InsertEnd(poly1, 5, 3);
    InsertEnd(poly1, 4, 2);
    InsertEnd(poly1, 2, 1);

    InsertEnd(poly2, 3, 3);
    InsertEnd(poly2, 2, 1);
    InsertEnd(poly2, 1, 0);

    cout << "First Example:" << endl;
    cout << "First Polynomial: ";
    Traverse(poly1);
    cout << "Second Polynomial: ";
    Traverse(poly2);
    poly3 = AddPolynomial(poly1, poly2);
    cout << "Resultant Polynomial: ";
    Traverse(poly3);
    cout << "-----------------------------" << endl;

    // Second Example
    Node* poly4 = NULL;
    Node* poly5 = NULL;
    Node* poly6 = NULL;

    InsertEnd(poly4, 7, 4);
    InsertEnd(poly4, 3, 2);
    InsertEnd(poly4, 1, 0);

    InsertEnd(poly5, 5, 3);
    InsertEnd(poly5, 2, 2);
    InsertEnd(poly5, 6, 0);

    cout << "Second Example:" << endl;
    cout << "First Polynomial: ";
    Traverse(poly4);
    cout << "Second Polynomial: ";
    Traverse(poly5);
    poly6 = AddPolynomial(poly4, poly5);
    cout << "Resultant Polynomial: ";
    Traverse(poly6);

    return 0;
}
