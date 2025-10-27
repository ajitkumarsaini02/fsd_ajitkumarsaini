 // Evaluation of Postfix Expression
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STACKSIZE 10

struct stack {
    int item[STACKSIZE];
    int top;
} S;

void Initialize() {
    S.top = -1;
}

int IsEmpty() {
    return (S.top == -1);
}

void push(int x) {
    if (S.top == STACKSIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    } else {
        S.top++;
        S.item[S.top] = x;
    }
}

int pop() {
    if (IsEmpty()) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        int x = S.item[S.top];
        S.top--;
        return x;
    }
}

int Evaluate(int x, int y, char symbol) {
    switch (symbol) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
        case '^': return (int)pow(x, y);
        default:
            printf("Invalid operator: %c\n", symbol);
            exit(1);
    }
}

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
    printf("Result: %d\n", pop());
}

int main() {
    char expression[100];
    printf("Enter postfix expression: ");
    scanf("%s", expression);

    postfixEvaluation(expression);

    return 0;
}
