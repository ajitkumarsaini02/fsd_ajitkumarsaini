// Polynomial Addition, Subtraction & Multiplication using Linked List

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node *next;
};

/* Create new node */
Node* GetNode(int coeff, int pow) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

/* Insert at end */
void InsertEnd(Node** poly, int coeff, int pow) {
    Node* newNode = GetNode(coeff, pow);
    if (*poly == NULL) {
        *poly = newNode;
        return;
    }
    Node* temp = *poly;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

/* Display polynomial */
void Traverse(Node* poly) {
    while (poly != NULL) {
        cout << poly->coeff << "x^" << poly->pow;
        poly = poly->next;
        if (poly != NULL)
            cout << " + ";
    }
    cout << endl;
}

/* ---------- ADDITION ---------- */
Node* AddPolynomial(Node* poly1, Node* poly2) {
    Node* poly3 = NULL;
    Node* p = poly1;
    Node* q = poly2;

    while (p != NULL && q != NULL) {
        if (p->pow == q->pow) {
            InsertEnd(&poly3, p->coeff + q->coeff, p->pow);
            p = p->next;
            q = q->next;
        }
        else if (p->pow > q->pow) {
            InsertEnd(&poly3, p->coeff, p->pow);
            p = p->next;
        }
        else {
            InsertEnd(&poly3, q->coeff, q->pow);
            q = q->next;
        }
    }

    while (p != NULL) {
        InsertEnd(&poly3, p->coeff, p->pow);
        p = p->next;
    }

    while (q != NULL) {
        InsertEnd(&poly3, q->coeff, q->pow);
        q = q->next;
    }

    return poly3;
}

/* ---------- SUBTRACTION ---------- */
Node* SubtractPolynomial(Node* poly1, Node* poly2) {
    Node* poly3 = NULL;
    Node* p = poly1;
    Node* q = poly2;

    while (p != NULL && q != NULL) {
        if (p->pow == q->pow) {
            InsertEnd(&poly3, p->coeff - q->coeff, p->pow);
            p = p->next;
            q = q->next;
        }
        else if (p->pow > q->pow) {
            InsertEnd(&poly3, p->coeff, p->pow);
            p = p->next;
        }
        else {
            InsertEnd(&poly3, -q->coeff, q->pow);
            q = q->next;
        }
    }

    while (p != NULL) {
        InsertEnd(&poly3, p->coeff, p->pow);
        p = p->next;
    }

    while (q != NULL) {
        InsertEnd(&poly3, -q->coeff, q->pow);
        q = q->next;
    }

    return poly3;
}

/* ---------- MULTIPLICATION ---------- */
Node* MultiplyPolynomial(Node* poly1, Node* poly2) {
    Node* poly3 = NULL;
    Node* p = poly1;

    while (p != NULL) {
        Node* q = poly2;
        while (q != NULL) {
            int coeff = p->coeff * q->coeff;
            int power = p->pow + q->pow;

            Node* temp = poly3;
            Node* prev = NULL;

            while (temp != NULL && temp->pow > power) {
                prev = temp;
                temp = temp->next;
            }

            if (temp != NULL && temp->pow == power) {
                temp->coeff += coeff;
            } else {
                Node* newNode = GetNode(coeff, power);
                if (prev == NULL) {
                    newNode->next = poly3;
                    poly3 = newNode;
                } else {
                    newNode->next = prev->next;
                    prev->next = newNode;
                }
            }
            q = q->next;
        }
        p = p->next;
    }
    return poly3;
}

/* Main Function */
int main() {
    Node *poly1 = NULL, *poly2 = NULL;
    Node *sum = NULL, *diff = NULL, *prod = NULL;

    // Polynomial 1: 5x^3 + 4x^2 + 2x^1
    InsertEnd(&poly1, 5, 3);
    InsertEnd(&poly1, 4, 2);
    InsertEnd(&poly1, 2, 1);

    // Polynomial 2: 3x^3 + 2x^1 + 1x^0
    InsertEnd(&poly2, 3, 3);
    InsertEnd(&poly2, 2, 1);
    InsertEnd(&poly2, 1, 0);

    cout << "First Polynomial: ";
    Traverse(poly1);

    cout << "Second Polynomial: ";
    Traverse(poly2);

    sum = AddPolynomial(poly1, poly2);
    cout << "Addition Result: ";
    Traverse(sum);

    diff = SubtractPolynomial(poly1, poly2);
    cout << "Subtraction Result: ";
    Traverse(diff);

    prod = MultiplyPolynomial(poly1, poly2);
    cout << "Multiplication Result: ";
    Traverse(prod);

    return 0;
}
