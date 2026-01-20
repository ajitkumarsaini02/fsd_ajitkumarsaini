// Array implementation of Stack
#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10

// Stack structure
struct stack {
    int item[STACKSIZE];
    int top;
} S;

/* Initialize Stack */
void Initialize() {
    S.top = -1;
}

/* Check if Stack is Empty */
int IsEmpty() {
    if (S.top == -1)
        return 1;
    else
        return 0;
}

/* Check if Stack is Full */
int IsFull() {
    if (S.top == STACKSIZE - 1)
        return 1;
    else
        return 0;
}

/* Push Operation */
void push(int x) {
    if (IsFull()) {
        printf("Stack Overflow\n");
        return;
    }
    S.top++;
    S.item[S.top] = x;
    printf("%d pushed into stack\n", x);
}

/* Pop Operation */
int pop() {
    if (IsEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    int x = S.item[S.top];
    S.top--;
    return x;
}

/* Peek / Stack Top */
int stackTop() {
    if (IsEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return S.item[S.top];
}

/* Display Stack */
void Display() {
    if (IsEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements (Top to Bottom):\n");
    for (int i = S.top; i >= 0; i--) {
        printf("%d\n", S.item[i]);
    }
}

/* Main Function */
int main() {
    Initialize();

    push(100);
    push(200);
    push(300);
    push(400);
    push(500);

    printf("\n");
    Display();

    printf("\nPopped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

    printf("\nTop element: %d\n", stackTop());

    printf("\nFinal Stack:\n");
    Display();

    return 0;
}
