 // Infix-to-postfix conversion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKSIZE 10

struct stack {
    char item[STACKSIZE];
    int top;
} S;

void Initialize() {
    S.top = -1;
}

int IsEmpty() {
    return (S.top == -1);
}

void push(char x) {
    if (S.top == STACKSIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    S.top++;
    S.item[S.top] = x;
}

char pop() {
    if (IsEmpty()) {
        printf("Stack underflow\n");
        exit(1);
    }
    char x = S.item[S.top];
    S.top--;
    return x;
}

char stackTop() {
    return S.item[S.top];
}

int prcd(char op1, char op2) {
    if (op1 == '^' || op1 == '*' || op1 == '/' || op1 == '%') {
        if (op2 == '^')
            return 0;
        else
            return 1;
    } else if (op1 == '+' || op1 == '-') {
        if (op2 == '+' || op2 == '-')
            return 1;
        else
            return 0;
    }
    return 0;
}

void infixToPostfix(char infix[]) {
    Initialize();
    char postfix[100];
    int i = 0, j = 0;
    char symb;

    while (infix[i] != '\0') {
        symb = infix[i];
        i++;

        // Operand
        if ((symb >= 'a' && symb <= 'z') || (symb >= 'A' && symb <= 'Z') || (symb >= '0' && symb <= '9')) {
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

    while (!IsEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; 

    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
