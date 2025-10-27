// Polynomial Addition, Subtraction & Multiplication using Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node *next;
};

struct Node* GetNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

void InsertEnd(struct Node** poly, int coeff, int pow) {
    struct Node* newNode = GetNode(coeff, pow);
    if (*poly == NULL) {
        *poly = newNode;
        return;
    }
    struct Node* temp = *poly;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void Traverse(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

// ---------- ADDITION ----------
struct Node* AddPolynomial(struct Node* poly1, struct Node* poly2) {
    struct Node* poly3 = NULL;
    struct Node* p = poly1;
    struct Node* q = poly2;

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

// ---------- SUBTRACTION ----------
struct Node* SubtractPolynomial(struct Node* poly1, struct Node* poly2) {
    struct Node* poly3 = NULL;
    struct Node* p = poly1;
    struct Node* q = poly2;

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

// ---------- MULTIPLICATION ----------
struct Node* MultiplyPolynomial(struct Node* poly1, struct Node* poly2) {
    struct Node* poly3 = NULL;
    struct Node* p = poly1;

    while (p != NULL) {
        struct Node* q = poly2;
        while (q != NULL) {
            int coeff = p->coeff * q->coeff;
            int pow = p->pow + q->pow;

            // Check if power already exists
            struct Node* temp = poly3;
            struct Node* prev = NULL;
            while (temp != NULL && temp->pow > pow) {
                prev = temp;
                temp = temp->next;
            }

            if (temp != NULL && temp->pow == pow) {
                temp->coeff += coeff;
            } else {
                struct Node* newNode = GetNode(coeff, pow);
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

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL;
    struct Node *sum = NULL, *diff = NULL, *prod = NULL;

    // Example 1:
    InsertEnd(&poly1, 5, 3);
    InsertEnd(&poly1, 4, 2);
    InsertEnd(&poly1, 2, 1);

    InsertEnd(&poly2, 3, 3);
    InsertEnd(&poly2, 2, 1);
    InsertEnd(&poly2, 1, 0);

    printf("First Polynomial: ");
    Traverse(poly1);
    printf("Second Polynomial: ");
    Traverse(poly2);

    sum = AddPolynomial(poly1, poly2);
    printf("Addition Result: ");
    Traverse(sum);

    diff = SubtractPolynomial(poly1, poly2);
    printf("Subtraction Result: ");
    Traverse(diff);

    prod = MultiplyPolynomial(poly1, poly2);
    printf("Multiplication Result: ");
    Traverse(prod);

    return 0;
}