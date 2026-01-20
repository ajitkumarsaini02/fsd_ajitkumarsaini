// Array implementation of Stack

#include <iostream>
using namespace std;

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
        cout << "Stack Overflow" << endl;
        return;
    }
    S.top++;
    S.item[S.top] = x;
    cout << x << " pushed into stack" << endl;
}

/* Pop Operation */
int pop() {
    if (IsEmpty()) {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    int x = S.item[S.top];
    S.top--;
    return x;
}

/* Peek / Stack Top */
int stackTop() {
    if (IsEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return S.item[S.top];
}

/* Display Stack */
void Display() {
    if (IsEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << "Stack elements (Top to Bottom):" << endl;
    for (int i = S.top; i >= 0; i--) {
        cout << S.item[i] << endl;
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

    cout << endl;
    Display();

    cout << "\nPopped element: " << pop() << endl;
    cout << "Popped element: " << pop() << endl;

    cout << "\nTop element: " << stackTop() << endl;

    cout << "\nFinal Stack:" << endl;
    Display();

    return 0;
}
