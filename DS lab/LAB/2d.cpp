// Infix-to-Postfix conversion

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define STACKSIZE 10

// Stack structure
struct stack {
    char item[STACKSIZE];
    int top;
} S;

/* Initialize Stack */
void Initialize() {
    S.top = -1;
}

/* Check if Stack is Empty */
int IsEmpty() {
    return (S.top == -1);
}

/* Push Operation */
void push(char x) {
    if (S.top == STACKSIZE - 1) {
        cout << "Stack overflow" << endl;
        exit(1);
    }
    S.top++;
    S.item[S.top] = x;
}

/* Pop Operation */
char pop() {
    if (IsEmpty()) {
        cout << "Stack underflow" << endl;
        exit(1);
    }
    char x = S.item[S.top];
    S.top--;
    return x;
}

/* Stack Top */
char stackTop() {
    return S.item[S.top];
}

/* Precedence Checking */
int prcd(char op1, char op2) {
    if (op1 == '^' || op1 == '*' || op1 == '/' || op1 == '%') {
        if (op2 == '^')
            return 0;
        else
            return 1;
    } 
    else if (op1 == '+' || op1 == '-') {
        if (op2 == '+' || op2 == '-')
            return 1;
        else
            return 0;
    }
    return 0;
}

/* Infix to Postfix Conversion */
void infixToPostfix(char infix[]) {
    Initialize();
    char postfix[100];
    int i = 0, j = 0;
    char symb;

    while (infix[i] != '\0') {
        symb = infix[i];
        i++;

        // Operand
        if ((symb >= 'a' && symb <= 'z') ||
            (symb >= 'A' && symb <= 'Z') ||
            (symb >= '0' && symb <= '9')) {
            postfix[j++] = symb;
        }
        // Operator
        else {
            while (!IsEmpty() && prcd(stackTop(), symb)) {
                postfix[j++] = pop();
            }
            push(symb);
        }
    }

    // Pop remaining operators
    while (!IsEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    cout << "Postfix Expression: " << postfix << endl;
}

/* Main Function */
int main() {
    char infix[100];

    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix);

    return 0;
}
