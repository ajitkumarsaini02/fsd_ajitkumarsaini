// Check for Balanced Parentheses using Stack

#include <iostream>
#include <cstdlib>
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

/* Function to check balanced parentheses */
void balanceParenthesis(char exp[]) {
    Initialize();
    int i = 0, flag = 0;

    while (exp[i] != '\0') {
        if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            if (!IsEmpty()) {
                pop();
            } else {
                flag = 1;   // Extra closing parenthesis
                break;
            }
        }
        i++;
    }

    if (IsEmpty()) {
        if (flag == 1)
            cout << "Invalid Expression" << endl;
        else
            cout << "Valid Expression" << endl;
    } else {
        cout << "Invalid Expression" << endl;
    }
}

/* Main Function */
int main() {
    char exp[100];

    cout << "Enter the expression: ";
    cin >> exp;

    balanceParenthesis(exp);

    return 0;
}
