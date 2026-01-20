// Evaluation of Postfix Expression

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

#define STACKSIZE 10

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
    return (S.top == -1);
}

/* Push Operation */
void push(int x) {
    if (S.top == STACKSIZE - 1) {
        cout << "Stack overflow" << endl;
        exit(1);
    } else {
        S.top++;
        S.item[S.top] = x;
    }
}

/* Pop Operation */
int pop() {
    if (IsEmpty()) {
        cout << "Stack underflow" << endl;
        exit(1);
    } else {
        int x = S.item[S.top];
        S.top--;
        return x;
    }
}

/* Evaluate Operation */
int Evaluate(int x, int y, char symbol) {
    switch (symbol) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
        case '^': return (int)pow(x, y);
        default:
            cout << "Invalid operator: " << symbol << endl;
            exit(1);
    }
}

/* Postfix Evaluation */
void postfixEvaluation(char postfix[]) {
    int i = 0;
    Initialize();

    while (postfix[i] != '\0') {
        char symbol = postfix[i];

        if (symbol >= '0' && symbol <= '9') {
            push(symbol - '0');
        } else {
            int y = pop();
            int x = pop();
            int value = Evaluate(x, y, symbol);
            push(value);
        }
        i++;
    }

    cout << "Result: " << pop() << endl;
}

/* Main Function */
int main() {
    char expression[100];

    cout << "Enter postfix expression: ";
    cin >> expression;

    postfixEvaluation(expression);

    return 0;
}
